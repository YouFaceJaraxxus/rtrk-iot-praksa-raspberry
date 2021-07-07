#include "post_request.h"


void initializePostBody(post_body *body, int measurementValue, int deviceId) {
  body->measurementValue = measurementValue;
  body->deviceId = deviceId;
  
  body->request = malloc(BUFFER_SIZE);
  if (body->request == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  body->request[0] = '\0';
  
  body->response = malloc(BUFFER_SIZE);
  if (body->response == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  body->response[0] = '\0';
  
  body->measurementString = malloc(VALUE_STRING_SIZE);
  if (body->measurementString == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  body->measurementString[0] = '\0';
  
  body->deviceIdString = malloc(DEVICE_ID_STRING_SIZE);
  if (body->deviceIdString == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  body->deviceIdString[0] = '\0';
}

void setBodyMeasurementValue(post_body* body, int newValue){
  body->measurementValue = newValue;
  sprintf(body->measurementString, "%d", newValue); 
}

void setBodyDeviceIdValue(post_body* body, int newDeviceId){
  body->deviceId = newDeviceId;
  sprintf(body->deviceIdString, "%d", newDeviceId); 
}

void setBodyRequest(post_body* body)
{
  char* requestPointer = body-> request;
  strcpy(requestPointer, "{\"measurement\":{\"value\":");
  strcat(requestPointer, body->measurementString);
  strcat(requestPointer, ",\"deviceId\":");
  strcat(requestPointer, body->deviceIdString);
  strcat(requestPointer, "}}");
}

void free_body(post_body *body)
{
  free(body->request);
  free(body->response);
  free(body->deviceIdString);
  free(body->measurementString);
}

size_t writeFunc(void *ptr, size_t size, size_t nmemb, post_body *body)
{
  size_t new_len = size*nmemb;
  memcpy(body->response, ptr, new_len);
  body->response[new_len] = '\0';

  return new_len;
}
