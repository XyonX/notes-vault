

1. A **copy-pasteable CLI script** (commands) that creates a clean, community-friendly layout for `PropertyFinder` with:
    
    - `PropertyFinder.sln` (solution)
        
    - `PropertyFinder.Backend` (ASP.NET Core Web API)
        
    - `PropertyFinder.Frontend` (MAUI app)
        
    - `PropertyFinder.Core` (shared class library for business/domain types — optional but recommended)
        
    - `PropertyFinder.Tests` (xUnit tests)
        
2. Short **explanations for each step**
    
3. A final **folder + file tree** so you can visualize the repo
    

> Note: these commands assume you have the .NET SDK installed and (for MAUI) the MAUI workload configured. If you haven’t installed MAUI workloads, `dotnet new maui` will fail — install workloads as per Microsoft docs before creating MAUI projects.

---

# 1) Copy-paste CLI script (cross-platform — bash / PowerShell works)

Run these from the folder where you want your repo (example: `~/projects/`).

```bash
# 0. Create root folder and enter it
mkdir PropertyFinder
cd PropertyFinder

# 1. Create solution at repo root
dotnet new sln -n PropertyFinder

# 2. Make conventional folders
mkdir -p src tests

# 3. Create a shared class library (recommended)
dotnet new classlib -n PropertyFinder.Core -o src/PropertyFinder.Core

# 4. Create backend (ASP.NET Core Web API)
dotnet new webapi -n PropertyFinder.Backend -o src/PropertyFinder.Backend

# 5. Create frontend (MAUI)
dotnet new maui -n PropertyFinder.Frontend -o src/PropertyFinder.Frontend

# 6. Create tests (xUnit)
dotnet new xunit -n PropertyFinder.Tests -o tests/PropertyFinder.Tests

# 7. Add projects to the solution
dotnet sln PropertyFinder.sln add src/PropertyFinder.Core/PropertyFinder.Core.csproj
dotnet sln PropertyFinder.sln add src/PropertyFinder.Backend/PropertyFinder.Backend.csproj
dotnet sln PropertyFinder.sln add src/PropertyFinder.Frontend/PropertyFinder.Frontend.csproj
dotnet sln PropertyFinder.sln add tests/PropertyFinder.Tests/PropertyFinder.Tests.csproj

# 8. Add project references
# Backend -> Core
dotnet add src/PropertyFinder.Backend/PropertyFinder.Backend.csproj reference src/PropertyFinder.Core/PropertyFinder.Core.csproj

# Frontend -> Core (if you want shared DTOs / services)
dotnet add src/PropertyFinder.Frontend/PropertyFinder.Frontend.csproj reference src/PropertyFinder.Core/PropertyFinder.Core.csproj

# Tests -> Backend and/or Core (test the core or backend internals)
dotnet add tests/PropertyFinder.Tests/PropertyFinder.Tests.csproj reference src/PropertyFinder.Core/PropertyFinder.Core.csproj

# 9. (Optional) Create a Directory.Build.props to centralize versions/TFM
cat > Directory.Build.props <<'XML'
<Project>
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <LangVersion>latest</LangVersion>
    <Nullable>enable</Nullable>
    <ImplicitUsings>enable</ImplicitUsings>
  </PropertyGroup>
</Project>
XML

# 10. Final: build the whole solution
dotnet build PropertyFinder.sln
```

---

# 2) Explanation of each step

- `mkdir PropertyFinder` / `cd PropertyFinder`  
    Create project root folder and move into it. Solution file lives here.
    
- `dotnet new sln -n PropertyFinder`  
    Create `PropertyFinder.sln` at repo root. This will be the container that points to all projects.
    
- `mkdir -p src tests`  
    Community convention: `src/` for application projects, `tests/` for test projects. Keeps repo tidy and relative paths short.
    
- `dotnet new classlib -n PropertyFinder.Core -o src/PropertyFinder.Core`  
    Create a shared class library for domain models and shared services. This prevents duplication of DTOs/models between backend & frontend.
    
- `dotnet new webapi -n PropertyFinder.Backend -o src/PropertyFinder.Backend`  
    Create an ASP.NET Core Web API as the backend. Will create `PropertyFinder.Backend.csproj` and default controllers.
    
- `dotnet new maui -n PropertyFinder.Frontend -o src/PropertyFinder.Frontend`  
    Create a .NET MAUI project for the frontend (cross-platform mobile/desktop UI). Requires MAUI workload installed.
    
- `dotnet new xunit -n PropertyFinder.Tests -o tests/PropertyFinder.Tests`  
    Create xUnit test project to hold unit/integration tests. You can add more test projects as needed.
    
- `dotnet sln add ...`  
    Register each `.csproj` with the solution. The `.sln` stores relative paths to these projects — this is how the solution “knows” the projects.
    
- `dotnet add <project> reference <other.csproj>`  
    Adds `<ProjectReference>` to the `.csproj`, letting you use types from the referenced project. This inserts a relative path in the `.csproj` file.
    
- `Directory.Build.props` (optional)  
    Central configuration file that will apply common properties to all projects (target framework, nullable context, implicit usings). Handy to keep project files DRY.
    
- `dotnet build PropertyFinder.sln`  
    Builds everything in the solution. Good sanity check.
    

---

# 3) Recommended names and what they mean

- Solution file: `PropertyFinder.sln` — represents the entire product.
    
- Project names (and resulting default namespaces/assemblies):
    
    - `PropertyFinder.Core` — shared domain models, DTOs, utility services
        
    - `PropertyFinder.Backend` — ASP.NET Core Web API (server)
        
    - `PropertyFinder.Frontend` — MAUI app (client)
        
    - `PropertyFinder.Tests` — xUnit tests (can target Core or Backend)
        
- Keep PascalCase and the dot-hierarchy: `Company.Product.Layer` pattern (here: `PropertyFinder.Layer`) for clarity.
    

---

# 4) Example folder + file tree (what you'll end up with)

```
PropertyFinder/                     <-- repo root (solution lives here)
├─ PropertyFinder.sln
├─ Directory.Build.props            <-- optional shared props
├─ README.md                        <-- (create manually)
├─ src/
│  ├─ PropertyFinder.Core/
│  │  ├─ PropertyFinder.Core.csproj
│  │  └─ Class1.cs                   <-- example: put domain models here (rename)
│  │
│  ├─ PropertyFinder.Backend/
│  │  ├─ PropertyFinder.Backend.csproj
│  │  ├─ Program.cs
│  │  ├─ appsettings.json
│  │  └─ Controllers/
│  │     └─ WeatherForecastController.cs
│  │
│  └─ PropertyFinder.Frontend/
│     ├─ PropertyFinder.Frontend.csproj
│     ├─ Platforms/
│     ├─ Resources/
│     ├─ MainPage.xaml
│     └─ (other MAUI files)
│
└─ tests/
   └─ PropertyFinder.Tests/
      ├─ PropertyFinder.Tests.csproj
      └─ UnitTest1.cs
```

---

# 5) A few practical tips & small edits you’ll likely want

- **Change Target Framework / MAUI TFMs:** MAUI projects typically target multi-target frameworks (android/ios/windows). Keep `Directory.Build.props` careful — if you set a single `TargetFramework` there, MAUI multi-targeting might be affected. You can instead put common props that apply only where appropriate (or wrap conditions). If unsure, leave MAUI project untouched and only centralize settings that apply to all .NET projects.
    
- **Project Names -> Assembly/Namespace:** If you ever need the assembly or default namespace to differ from the `.csproj` filename, set `<AssemblyName>` or `<RootNamespace>` inside that `.csproj`.
    
- **ProjectReferences use relative paths:** When you added references, the `<ProjectReference>` includes a relative path (e.g., `..\PropertyFinder.Core\PropertyFinder.Core.csproj`). If you move a folder, update references with `dotnet sln remove`/`add` or manually edit the path.
    
- **Version control:** Add `.gitignore` (use `dotnet new gitignore`) and commit the `.sln`, all `.csproj` files, and source code. Don’t commit `bin/`/`obj/`.
    

---

# 6) Quick edits you might want to make immediately

Open `src/PropertyFinder.Backend/Program.cs` and set the launch urls or CORS policies for local development.  
Open `src/PropertyFinder.Frontend/Platforms` for platform-specific settings (Android/iOS/Windows).  
Place shared DTOs (e.g., `PropertyDto`) in `PropertyFinder.Core/Models/` so both backend and frontend can reference them.

---

If you want, I can now:

- produce the **exact `Directory.Build.props`** adjusted so MAUI is not broken (I can give a robust example),
    
- or generate a **starter `PropertyDto`** and wire up a minimal backend controller and an example MAUI page that calls the backend (example code + where to put files).
    

Which of those do you want next?