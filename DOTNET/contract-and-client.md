

# What they are and why people add them

### `PropertyFinder.Contracts`

- **Purpose:** Holds shared **data contracts (DTOs)** and small, platform-agnostic **interfaces** that describe the shape of messages exchanged between services (e.g., `PropertySummary`, `CreatePropertyRequest`) and sometimes service contracts (e.g., interfaces describing API surface).
    
- **Why use it:** Keeps the canonical model in one place so Backend and Frontend (and any other consumers) agree on the types. Avoids duplication.
    
- **What to avoid putting here:** UI, platform-specific code, or heavy dependencies (e.g., System.Windows). Keep it minimal and dependency-free.
    

### `PropertyFinder.Client`

- **Purpose:** Holds **client-side implementation(s)** that call the backend — e.g., an `IPropertyService` interface plus an `HttpPropertyService` implementation that uses `HttpClient`, Refit, or generated code from OpenAPI.
    
- **Why use it:** Encapsulates HTTP calls, serialisation, retry policies, and mapping. Frontend (MAUI) depends on `Client` and consumes `IPropertyService`, keeping UI code clean and testable.
    
- **Alternative:** Instead of a project, generate clients from OpenAPI/Swagger and either commit them or publish as a NuGet package.
    

---

# Where they sit in the repo

Typical layout (sibling to Backend/Frontend/Core):

```
src/
  PropertyFinder.Core/        <-- domain & shared business logic (optional)
  PropertyFinder.Contracts/   <-- DTOs and interfaces (no heavy deps)
  PropertyFinder.Client/      <-- Http client + concrete implementations
  PropertyFinder.Backend/     <-- API implementation (references Contracts)
  PropertyFinder.Frontend/    <-- MAUI app (references Client and/or Contracts)
```

Why this layout? It prevents circular references and keeps responsibilities clear:

- Backend references `Contracts` (to implement DTOs)
    
- Client references `Contracts` (to use DTOs and interfaces)
    
- Frontend references `Client` (to call services)
    
- Core can be referenced by Backend/Client (depending on design)
    

---

# CLI: create these projects and wire them (copy/paste)

Run from `PropertyFinder` repo root (you may already have `sln` and other projects):

```bash
# create contracts and client projects
dotnet new classlib -n PropertyFinder.Contracts -o src/PropertyFinder.Contracts
dotnet new classlib -n PropertyFinder.Client -o src/PropertyFinder.Client

# add to solution
dotnet sln PropertyFinder.sln add src/PropertyFinder.Contracts/PropertyFinder.Contracts.csproj
dotnet sln PropertyFinder.sln add src/PropertyFinder.Client/PropertyFinder.Client.csproj

# wire references
# Backend needs Contracts
dotnet add src/PropertyFinder.Backend/PropertyFinder.Backend.csproj reference src/PropertyFinder.Contracts/PropertyFinder.Contracts.csproj

# Client needs Contracts
dotnet add src/PropertyFinder.Client/PropertyFinder.Client.csproj reference src/PropertyFinder.Contracts/PropertyFinder.Contracts.csproj

# Frontend consumes Client (and optionally Contracts)
dotnet add src/PropertyFinder.Frontend/PropertyFinder.Frontend.csproj reference src/PropertyFinder.Client/PropertyFinder.Client.csproj
# optional: frontend can also reference contracts directly if needed
# dotnet add src/PropertyFinder.Frontend/PropertyFinder.Frontend.csproj reference src/PropertyFinder.Contracts/PropertyFinder.Contracts.csproj
```

---

# Minimal example contents

**`src/PropertyFinder.Contracts/Models/PropertySummary.cs`**

```csharp
namespace PropertyFinder.Contracts.Models;

public record PropertySummary(
    Guid Id,
    string Title,
    string City,
    decimal Price,
    int Bedrooms,
    string ThumbnailUrl
);
```

**`src/PropertyFinder.Contracts/IPropertyService.cs`** _(optional: contract for the service surface)_

```csharp
namespace PropertyFinder.Contracts;

using PropertyFinder.Contracts.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

public interface IPropertyService
{
    Task<IEnumerable<PropertySummary>> GetTopPropertiesAsync(int count = 10);
    Task<PropertySummary?> GetPropertyAsync(Guid id);
}
```

**`src/PropertyFinder.Client/Http/HttpPropertyService.cs`**

```csharp
using PropertyFinder.Contracts;
using PropertyFinder.Contracts.Models;
using System.Net.Http.Json;

namespace PropertyFinder.Client.Http;

public class HttpPropertyService : IPropertyService
{
    private readonly HttpClient _http;

    public HttpPropertyService(HttpClient http) => _http = http;

    public async Task<IEnumerable<PropertySummary>> GetTopPropertiesAsync(int count = 10)
    {
        var resp = await _http.GetFromJsonAsync<IEnumerable<PropertySummary>>($"/api/properties/top?count={count}");
        return resp ?? Array.Empty<PropertySummary>();
    }

    public async Task<PropertySummary?> GetPropertyAsync(Guid id)
    {
        return await _http.GetFromJsonAsync<PropertySummary>($"/api/properties/{id}");
    }
}
```

**Registration in MAUI `MauiProgram.cs` (or Startup)**

```csharp
using PropertyFinder.Client.Http;

builder.Services.AddHttpClient<IPropertyService, HttpPropertyService>(client =>
{
    client.BaseAddress = new Uri("https://localhost:5001"); // dev backend URL
});
```

**Backend Controller snippet that returns `PropertySummary`**

```csharp
[ApiController]
[Route("api/properties")]
public class PropertiesController : ControllerBase
{
    [HttpGet("top")]
    public IEnumerable<PropertySummary> GetTop(int count = 10) =>
        Enumerable.Range(1, count).Select(i => new PropertySummary(Guid.NewGuid(), $"Property {i}", "Kolkata", 123456 + i, 2, "/img/1.jpg"));
}
```

---

# Notes & best practices

- **Avoid coupling Contracts to UI**: Contracts should be pure data + small interfaces, no UI types.
    
- **Target frameworks**: Use a common target (e.g., `net8.0`) so Projects can reference each other easily. If you need compatibility with older frameworks, consider multi-targeting (e.g., `TargetFrameworks`).
    
- **Circular dependencies**: Don’t make Backend reference Client. Client references Contracts; Backend references Contracts — that prevents cycles.
    
- **Publishing across repos**: If Backend and Frontend live in separate repos, consider publishing `PropertyFinder.Contracts` (and `Client`) as versioned NuGet packages.
    
- **Code generation**: For larger API surfaces, prefer generating the client from an OpenAPI/Swagger spec (NSwag/AutoRest/NSwag.MSBuild). It reduces drift between API and client.
    
- **Versioning**: Contracts evolve; version them (e.g., `Contracts.v1` or use semantic NuGet versions) to avoid breaking clients.
    

---

# Final folder tree (including Contracts & Client)

```
PropertyFinder/
├─ PropertyFinder.sln
├─ src/
│  ├─ PropertyFinder.Contracts/
│  │  ├─ PropertyFinder.Contracts.csproj
│  │  └─ Models/
│  │     └─ PropertySummary.cs
│  │
│  ├─ PropertyFinder.Client/
│  │  ├─ PropertyFinder.Client.csproj
│  │  └─ Http/
│  │     └─ HttpPropertyService.cs
│  │
│  ├─ PropertyFinder.Core/        (optional)
│  ├─ PropertyFinder.Backend/
│  └─ PropertyFinder.Frontend/
└─ tests/
   └─ PropertyFinder.Tests/
```

---

If you want, I can:

- generate the exact files for `Contracts` and `Client` and show the complete `.csproj` contents (multi-target suggestions),
    
- or show how to generate a typed client from an OpenAPI spec (NSwag) and wire it into MAUI.
    

Which one would help you next?