#include "get_request.h"


void initializeGetResponse(get_response *response) {
  response->response = malloc(BUFFER_SIZE);
  if (response->response == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  response->response[0] = '\0';
}

void free_response(get_response *response)
{
  free(response->response);
}

size_t writeFunc(void *ptr, size_t size, size_t nmemb, get_response *response)
{
  size_t new_len = size*nmemb;
  memcpy(response->response, ptr, new_len);
  response->response[new_len] = '\0';

  return new_len;
}
