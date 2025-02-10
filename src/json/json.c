#include "json.h";


void nextChar(json_parser* p) {

    p->currentIndex++;
    p->currentChar = p->currentChar[p->currentIndex];
    return;
}


TOKEN_TYPE toType(json_parser* p) {


    while (isspace(p->currentChar))
    {
        nextChar(p);
    }
    
    

    switch (p->currentChar[0])
    {
    case '{':
        return CURLY_OPEN_BRACKET;

    case '}':
        return CURLY_CLOSE_BRACKET;

    case '[':
        return SQUARE_OPEN_BRACKET;
    
    case ']':
        return SQUARE_CLOSE_BRACKET;


    case ',':
        return COMMA;

    case ':':
        return DOUBLE_POINT;

    default:
        return SYMBOL;
    }    

    return SYMBOL;

}

int accept(TOKEN_TYPE type, json_parser* p) {

    if(type == toType(p)) {

        nextChar(p);
        return 1;
    }

    return 0;

}


json_parser* init_parser(char* source) {

    json_parser p = {0};
    p.currentChar = source[0];
    p.currentIndex = 0;
    p.source = source;
    return &p;
}


JsonObject* parseJsonArray(json_parser* p) {

    return NULL;
}

JsonObject* parseJsonObject(json_parser* p) {

    return NULL;
}


json* parseJsonFromString(char* JsonString) {
    json_parser* p = init_parser(JsonString);


    char* currentType = toType(p);

    if(accept(CURLY_OPEN_BRACKET, p)) {
        json* JSON = malloc(sizeof(json));
        JSON->body = parseJsonObject(p);


        return JSON;


    } 

    else if(accept(SQUARE_OPEN_BRACKET,p)) {
        json* JSON = malloc(sizeof(json));

        JSON->body = parseJsonArray(p);
        return JSON;
    
    } else {
        

        error("JSON have to start with an object or an Array!");
        return NULL;
    }


    

}