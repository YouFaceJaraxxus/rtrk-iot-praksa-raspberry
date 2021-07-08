#include "post_request.h"

char* initializeCharArray(int size)
{
  char *array = malloc(size);
  array[0] = '\0';
  return array;
}


void setBodyTemperatureValue(post_body* body, float value){
  body->temperatureValue = value;
  sprintf(body->temperatureString, "%.2f", value); 
}

void setBodyGyroXValue(post_body* body, float value){
  body->gyroXValue = value;
  sprintf(body->gyroXString, "%.2f", value); 
}

void setBodyGyroYValue(post_body* body, float value){
  body->gyroYValue = value;
  sprintf(body->gyroYString, "%.2f", value); 
}

void setBodyGyroZValue(post_body* body, float value){
  body->gyroZValue = value;
  sprintf(body->gyroZString, "%.2f", value); 
}

void setBodyAccXValue(post_body* body, float value){
  body->accXValue = value;
  sprintf(body->accXString, "%.2f", value); 
}

void setBodyAccYValue(post_body* body, float value){
  body->accYValue = value;
  sprintf(body->accYString, "%.2f", value); 
}

void setBodyAccZValue(post_body* body, float value){
  body->accZValue = value;
  sprintf(body->accZString, "%.2f", value); 
}

void setBodyMagXValue(post_body* body, float value){
  body->magXValue = value;
  sprintf(body->magXString, "%.2f", value); 
}

void setBodyMagYValue(post_body* body, float value){
  body->magYValue = value;
  sprintf(body->magYString, "%.2f", value); 
}

void setBodyMagZValue(post_body* body, float value){
  body->magZValue = value;
  sprintf(body->magZString, "%.2f", value); 
}

void initializePostBody(post_body *body, int deviceId) {  
  body->request = initializeCharArray(BUFFER_SIZE);
  body->response = initializeCharArray(BUFFER_SIZE);
  
  body->deviceIdString = initializeCharArray(DEVICE_ID_STRING_SIZE);
  setBodyDeviceIdValue(body, deviceId);
  
  body->temperatureString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyTemperatureValue(body, 0);
  
  body->gyroXString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyGyroXValue(body, 0);
  body->gyroYString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyGyroYValue(body, 0);
  body->gyroZString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyGyroZValue(body, 0);
  
  body->accXString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyAccXValue(body, 0);
  body->accYString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyAccYValue(body, 0);
  body->accZString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyAccZValue(body, 0);
  
  body->magXString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyMagXValue(body, 0);
  body->magYString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyMagYValue(body, 0);
  body->magZString = initializeCharArray(VALUE_STRING_SIZE);
  setBodyMagZValue(body, 0);
}

void setBodyStrings(post_body *body)
{
  sprintf(body->deviceIdString, "%d", body->deviceId); 
  
  sprintf(body->gyroXString, "%.2f", body->gyroXValue); 
  sprintf(body->gyroYString, "%.2f", body->gyroYValue); 
  sprintf(body->gyroZString, "%.2f", body->gyroZValue); 
  
  sprintf(body->accXString, "%.2f", body->accXValue); 
  sprintf(body->accYString, "%.2f", body->accYValue); 
  sprintf(body->accZString, "%.2f", body->accZValue); 
  
  sprintf(body->magXString, "%.2f", body->magXValue); 
  sprintf(body->magYString, "%.2f", body->magYValue); 
  sprintf(body->magZString, "%.2f", body->magZValue); 
}

void setBodyMeasurementValue(post_body* body, int key, float value){
  switch(key)
  {
    case TEMPERATURE:
      setBodyTemperatureValue(body, value);
      break;
    case GYRO_X:
      setBodyGyroXValue(body, value);
      break;
    case GYRO_Y:
      setBodyGyroYValue(body, value);
      break;
    case GYRO_Z:
      setBodyGyroZValue(body, value);
      break;
    case ACC_X:
      setBodyAccXValue(body, value);
      break;
    case ACC_Y:
      setBodyAccYValue(body, value);
      break;
    case ACC_Z:
      setBodyAccZValue(body, value);
      break;
    case MAG_X:
      setBodyMagXValue(body, value);
      break;
    case MAG_Y:
      setBodyMagYValue(body, value);
      break;
    case MAG_Z:
      setBodyMagZValue(body, value);
      break;
  }
}

void setBodyMeasurementValues(
  post_body* body, 
  float temperatureValue,
  float gyroXValue,
  float gyroYValue,
  float gyroZValue,
  float accXValue,
  float accYValue,
  float accZValue,
  float magXValue,
  float magYValue,
  float magZValue
)
{
  setBodyTemperatureValue(body, temperatureValue);
  
  setBodyGyroXValue(body, gyroXValue);
  setBodyGyroYValue(body, gyroYValue);
  setBodyGyroZValue(body, gyroZValue);
  
  setBodyAccXValue(body, accXValue);
  setBodyAccYValue(body, accYValue);
  setBodyAccZValue(body, accZValue);
  
  setBodyMagXValue(body, magXValue);
  setBodyMagYValue(body, magYValue);
  setBodyMagZValue(body, magZValue);
}

void setBodyDeviceIdValue(post_body* body, int deviceId){
  body->deviceId = deviceId;
  sprintf(body->deviceIdString, "%d", deviceId); 
}

void setBodyRequest(post_body* body)
{
  char* requestPointer = body-> request;
  strcpy(requestPointer, "{\"measurement\":{\"temperature\":");
  strcat(requestPointer, body->temperatureString);
  
  strcat(requestPointer, ",\"gyroX\":");
  strcat(requestPointer, body->gyroXString);
  strcat(requestPointer, ",\"gyroY\":");
  strcat(requestPointer, body->gyroYString);
  strcat(requestPointer, ",\"gyroZ\":");
  strcat(requestPointer, body->gyroZString);
  
  strcat(requestPointer, ",\"accX\":");
  strcat(requestPointer, body->accXString);
  strcat(requestPointer, ",\"accY\":");
  strcat(requestPointer, body->accYString);
  strcat(requestPointer, ",\"accZ\":");
  strcat(requestPointer, body->accZString);
  
  strcat(requestPointer, ",\"magX\":");
  strcat(requestPointer, body->magXString);
  strcat(requestPointer, ",\"magY\":");
  strcat(requestPointer, body->magYString);
  strcat(requestPointer, ",\"magZ\":");
  strcat(requestPointer, body->magZString);
  
  strcat(requestPointer, ",\"deviceId\":");
  strcat(requestPointer, body->deviceIdString);
  strcat(requestPointer, "}}");
}

void free_body(post_body *body)
{
  free(body->request);
  free(body->response);
  
  free(body->deviceIdString);
  
  free(body->temperatureString);
  
  
  free(body->gyroXString);
  free(body->gyroYString);
  free(body->gyroZString);
  
  free(body->accXString);
  free(body->accYString);
  free(body->accZString);
  
  free(body->magXString);
  free(body->magYString);
  free(body->magZString);
}

size_t writeFunc(void *ptr, size_t size, size_t nmemb, post_body *body)
{
  size_t new_len = size*nmemb;
  memcpy(body->response, ptr, new_len);
  body->response[new_len] = '\0';

  return new_len;
}
