#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include "get_request.h"

int main(void)
{
  CURL *curl;

  curl = curl_easy_init();
  if(curl) {
    get_response response;
    initializeGetResponse(&response);

    curl_easy_setopt(curl, CURLOPT_URL, "https://rtrk-iot-praksa.herokuapp.com/api/data");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);

    printf("%s\n", response.response);
    free_response(&response);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

