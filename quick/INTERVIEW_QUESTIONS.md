# LungScan Project - Backend Technical Interview Questions & Answers

## Project Overview

**LungScan** is a comprehensive AI-powered lung cancer detection system that I developed as my final year project. The system analyzes histopathological images of lung tissue to detect and classify lung cancer types with high accuracy.

### Architecture
- **Frontend**: React.js with Bootstrap (Vite build system)
- **Backend**: Node.js/Express.js (primary) + Flask (secondary)
- **AI/ML**: TensorFlow/Keras model for image classification
- **Deployment**: Render.com (both Node.js and Flask services)

---

## Backend Architecture Questions

### 1. What was your role in the backend development?

**Answer:**
As the backend developer, I was responsible for:
- Designing and implementing the Node.js/Express.js API server
- Creating the file upload and processing pipeline
- Integrating with the Flask ML model for predictions
- Managing file storage and cleanup
- Implementing error handling and validation
- Setting up deployment configuration

### 2. How did you structure the Node.js backend?

**Answer:**
```javascript
// Core dependencies
const express = require("express");
const cors = require("cors");
const multer = require("multer");
const axios = require("axios");
const fs = require("fs");

// Server setup
const app = express();
const PORT = process.env.PORT || 3009;

// Middleware configuration
app.use(express.json());
app.use(cors({ origin: "*" }));

// File upload configuration
const upload = multer({ dest: "uploads/" });
```

### 3. Explain the file upload and processing pipeline

**Answer:**
1. **File Reception**: Client uploads image via multipart/form-data
2. **Temporary Storage**: Multer stores file in `uploads/` directory
3. **Form Data Creation**: File is read and converted to FormData
4. **Flask API Call**: FormData is sent to Flask ML model endpoint
5. **Cleanup**: Original file is deleted after processing
6. **Response**: Prediction results are returned to client

```javascript
app.post("/predict", upload.single("file"), async (req, res) => {
  try {
    if (!req.file) {
      return res.status(400).json({ error: "No file uploaded" });
    }

    const imagePath = path.resolve(req.file.path);
    const formData = new FormData();
    formData.append("file", fs.createReadStream(imagePath));

    const response = await axios.post(
      "https://flask-api-g4ld.onrender.com/predict",
      formData,
      { headers: formData.getHeaders() }
    );

    fs.unlinkSync(imagePath); // Cleanup
    res.json(response.data);
  } catch (error) {
    res.status(500).json({ error: "Internal Server Error" });
  }
});
```

### 4. Why did you choose a dual-backend architecture (Node.js + Flask)?

**Answer:**
- **Node.js**: Excellent for handling HTTP requests, file uploads, and API routing
- **Flask**: Better suited for ML model integration and TensorFlow operations
- **Separation of Concerns**: Each service handles its specialty
- **Scalability**: Independent scaling of API and ML components
- **Deployment**: Different deployment strategies for web services vs ML models

### 5. How did you handle file uploads securely?

**Answer:**
- **Multer Configuration**: Limited file size and type restrictions
- **Temporary Storage**: Files stored only temporarily in `uploads/` directory
- **Immediate Cleanup**: Files deleted immediately after processing
- **Path Validation**: Used `path.resolve()` to prevent path traversal
- **Error Handling**: Comprehensive error handling for file operations

### 6. What error handling strategies did you implement?

**Answer:**
```javascript
try {
  // File processing logic
} catch (error) {
  console.error("Error processing image:", error.message);
  res.status(500).json({
    error: error.response ? error.response.data : "Internal Server Error",
  });
}
```

- **400 Errors**: Invalid requests, missing files
- **500 Errors**: Server errors, ML model failures
- **Logging**: Comprehensive error logging for debugging
- **Graceful Degradation**: Fallback responses for failed operations

### 7. How did you integrate with the Flask ML model?

**Answer:**
- **HTTP Client**: Used Axios for making POST requests to Flask API
- **FormData**: Converted files to FormData for multipart upload
- **Headers**: Set appropriate headers for file upload
- **Response Handling**: Parsed and forwarded ML predictions

```javascript
const response = await axios.post(
  "https://flask-api-g4ld.onrender.com/predict",
  formData,
  { headers: formData.getHeaders() }
);
```

### 8. What deployment considerations did you make?

**Answer:**
- **Environment Variables**: Used dotenv for configuration management
- **Port Configuration**: Dynamic port assignment for deployment platforms
- **Process Management**: Used nodemon for development, PM2 for production
- **Health Checks**: Implemented basic health endpoints
- **Logging**: Structured logging for monitoring

### 9. How did you handle CORS and security?

**Answer:**
```javascript
app.use(cors({ origin: "*" })); // Development
// In production: restrict to specific domains
app.use(cors({ origin: ["https://yourdomain.com"] }));
```

- **CORS Configuration**: Allowed cross-origin requests from frontend
- **Input Validation**: Validated file types and sizes
- **Rate Limiting**: (Future improvement) Implement rate limiting
- **HTTPS**: Deployed over HTTPS for secure communication

### 10. What were the main challenges and how did you overcome them?

**Answer:**
1. **File Upload Size**: Optimized multer configuration for large medical images
2. **ML Model Integration**: Created robust error handling for TensorFlow operations
3. **Performance**: Implemented efficient file cleanup to prevent storage issues
4. **Deployment**: Configured both Node.js and Flask services on Render.com
5. **Cross-platform Communication**: Ensured seamless API communication between services

---

## Flask Backend Questions

### 11. What was the role of the Flask backend?

**Answer:**
The Flask backend served as the ML inference server:
- **Model Loading**: Dynamically loaded TensorFlow model to prevent memory issues
- **Image Preprocessing**: Resized and normalized images for model input
- **Prediction**: Made predictions using the loaded model
- **Response Formatting**: Formatted predictions for API consumption

### 12. How did you optimize model loading in Flask?

**Answer:**
```python
def get_model():
    """Load model dynamically to prevent memory issues."""
    global model
    if model is None:
        try:
            print("⚡ Loading model...")
            model = tf.keras.models.load_model(model_path)
            print("✅ Model loaded successfully!")
        except Exception as e:
            print(f"❌ Error loading model: {e}")
            model = None
    return model
```

- **Lazy Loading**: Model loaded only when first request arrives
- **Global Variable**: Cached model in memory for subsequent requests
- **Error Handling**: Graceful handling of model loading failures

### 13. Describe the image preprocessing pipeline

**Answer:**
```python
def preprocess_image(image_file):
    """Preprocess image for prediction."""
    try:
        img = Image.open(image_file).convert("RGB")
        img = img.resize((150, 150))
        img_array = image.img_to_array(img) / 255.0  # Normalize
        img_array = np.expand_dims(img_array, axis=0)
        return img_array
    except Exception as e:
        raise ValueError(f"Error processing image: {str(e)}")
```

- **Format Conversion**: Converted to RGB format
- **Resizing**: Standardized to 150x150 pixels
- **Normalization**: Scaled pixel values to [0, 1]
- **Batch Dimension**: Added batch dimension for model input

### 14. How did you handle different lung cancer types?

**Answer:**
```python
# Class labels
class_labels = ["lung_aca", "lung_scc", "lung_n"]

# Prediction handling
prediction = model.predict(processed_image)
predicted_class = np.argmax(prediction)
confidence = float(np.max(prediction) * 100)
```

- **Three Classes**: Adenocarcinoma (lung_aca), Squamous Cell Carcinoma (lung_scc), Normal (lung_n)
- **Confidence Scoring**: Calculated prediction confidence percentage
- **Label Mapping**: Mapped model output to human-readable labels

---

## Integration & Communication Questions

### 15. How did the frontend communicate with the backend?

**Answer:**
```javascript
const response = await axios.post(
  "https://express-api-lungscan.onrender.com/predict",
  formData,
  { headers: { "Content-Type": "multipart/form-data" } }
);
```

- **HTTP Client**: Used Axios for API calls
- **FormData**: Proper multipart form data for file uploads
- **Error Handling**: Comprehensive error handling in frontend
- **State Management**: React state for managing upload and prediction results

### 16. What testing strategies did you use?

**Answer:**
- **Manual Testing**: Extensive manual testing of file uploads and predictions
- **Error Scenario Testing**: Tested various error conditions
- **Performance Testing**: Tested with different image sizes
- **Integration Testing**: Verified communication between Node.js and Flask

### 17. How did you ensure scalability?

**Answer:**
- **Microservices Architecture**: Independent scaling of API and ML services
- **Efficient Resource Usage**: Dynamic model loading and file cleanup
- **Stateless Design**: No session state, easy horizontal scaling
- **Load Balancing**: (Future) Implement load balancing for high traffic

### 18. What monitoring and logging did you implement?

**Answer:**
- **Console Logging**: Detailed logging for debugging
- **Error Tracking**: Comprehensive error logging
- **Performance Metrics**: Response time tracking
- **Health Monitoring**: Basic health check endpoints

### 19. How did you handle different file formats?

**Answer:**
- **Supported Formats**: JPEG, PNG, DICOM (medical imaging format)
- **Format Validation**: Frontend validation for supported formats
- **Image Processing**: PIL library handles various image formats
- **Conversion**: Automatic conversion to RGB format for model input

### 20. What improvements would you make?

**Answer:**
1. **Enhanced Security**: Implement authentication and authorization
2. **Rate Limiting**: Add rate limiting to prevent abuse
3. **Caching**: Implement response caching for repeated predictions
4. **Monitoring**: Add comprehensive monitoring and alerting
5. **Documentation**: Create detailed API documentation
6. **Testing**: Implement automated testing suite
7. **Performance**: Optimize model inference time
8. **Scalability**: Implement load balancing and auto-scaling

---

## Technical Skills Demonstrated

### Backend Development
- Node.js/Express.js API development
- File upload handling with Multer
- HTTP client integration with Axios
- Error handling and validation
- Deployment configuration

### ML Integration
- Flask API development
- TensorFlow/Keras model integration
- Image preprocessing and normalization
- Dynamic model loading

### Full-stack Integration
- Cross-service communication
- Frontend-backend integration
- State management in React
- API design and documentation

### DevOps & Deployment
- Environment configuration
- Service deployment on Render.com
- Process management
- Monitoring and logging

This project demonstrates comprehensive backend development skills, ML integration capabilities, and full-stack development experience, making it an excellent showcase for technical interviews.
