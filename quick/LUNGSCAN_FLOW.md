# LungScan App – Flow & Functionality

## Overview

LungScan is an AI-powered system for detecting and classifying lung cancer from histopathological images. It uses a dual-backend architecture with a React frontend, a Node.js/Express API server, and a Flask ML inference server.

---

## Application Flow

1. **User Uploads Image**
   - The frontend (React) provides a UI for users to upload lung tissue images.

2. **File Reception & Temporary Storage**
   - The image is sent to the Node.js backend via a POST request (`/predict` endpoint).
   - Multer middleware stores the uploaded file temporarily in the `uploads/` directory.

3. **Forwarding to ML Model**
   - The Node.js backend reads the file and creates a FormData object.
   - It sends the image to the Flask backend’s `/predict` endpoint using Axios.

4. **ML Prediction**
   - The Flask server loads the TensorFlow/Keras model (if not already loaded).
   - The image is preprocessed (resized, normalized, batch dimension added).
   - The model predicts the lung cancer type and confidence score.

5. **Result Handling & Cleanup**
   - The Flask backend returns the prediction result to the Node.js backend.
   - The Node.js backend deletes the temporary file from `uploads/`.
   - The prediction result is sent back to the frontend.

6. **Frontend Displays Result**
   - The frontend receives and displays the prediction and confidence to the user.

---

## Key Functionalities

### Frontend (React)
- User authentication (optional/future)
- Image upload interface
- Displays prediction results and errors
- Handles loading and error states

### Node.js/Express Backend
- Handles file uploads with Multer
- Forwards files to Flask ML API
- Cleans up temporary files after processing
- Implements error handling and validation
- Manages CORS and security settings

### Flask Backend (ML Inference)
- Loads and caches TensorFlow/Keras model
- Preprocesses images for prediction
- Predicts lung cancer type (adenocarcinoma, squamous cell carcinoma, normal)
- Returns prediction and confidence score

### DevOps & Deployment
- Environment variable management
- Deployment on Render.com (both Node.js and Flask)
- Health check endpoints
- Logging and monitoring

---

## Security & Best Practices

- File type and size validation
- Immediate file cleanup after processing
- Path validation to prevent traversal attacks
- CORS configuration for secure cross-origin requests
- Error handling for both backend services

---

## Future Improvements

- Authentication and authorization
- Rate limiting
- Automated testing
- Enhanced monitoring and alerting
- Load balancing and auto-scaling

---
