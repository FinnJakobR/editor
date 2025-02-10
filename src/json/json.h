#ifndef JSON_H
#define JSON_H
#define ARRAY_SIZE 10;

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/* {
    hello: {},

} */




typedef enum {
    JSON_INT,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_BOOL,
} JSON_TYPE;


typedef struct 
{
    char* data;
    size_t start;
    size_t end;
    size_t size;
} JsonString;




typedef struct {
  void *array;
  size_t used;
  size_t size;
} Array;



typedef struct 
{
    char* source;
    char* currentChar; 
    size_t currentIndex; 
} json_parser;



typedef struct
{
    JsonValue **items;
    size_t count;
    size_t used;
} JsonArray;

typedef struct 
{
    JSON_TYPE type;
    union
    {
        JsonString* str;
        JsonArray* arr;
        JsonObject* obj;
    };
    


} JsonValue;


typedef struct 
{
    JsonString* key;
    JsonValue* value;

} JsonPair;



typedef struct 
{
    JsonPair* pairs;
    size_t count;
} JsonObject;



typedef struct
{
    JsonObject* body;
} json;


json* parseJsonFromString(char* jsonString);
json* parseJsonFromFile(char* fileName);



#endif