#ifndef POST_REQUEST_H
#define POST_REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#define BUFFER_SIZE 10240 //10 kB
#define VALUE_STRING_SIZE 20 //10 kB
#define DEVICE_ID_STRING_SIZE 10 //10 kB

typedef struct post_body {
  char *measurementString;
  char *deviceIdString;
  char *request;
  char *response;
  int measurementValue;
  int deviceId;
} post_body;


void initializePostBody(post_body *body, int measurementValue, int deviceId);
void setBodyMeasurementValue(post_body* body, int newValue);
void setBodyDeviceIdValue(post_body* body, int newDeviceId);
void setBodyRequest(post_body* body);
void free_body(post_body *body);
size_t writeFunc(void *ptr, size_t size, size_t nmemb, post_body *body);

#endif /* POST_REQUEST_H */
