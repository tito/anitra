#include <stdio.h>
#include "core.h"
#include <game.h>
#include <externals.h>
#include <engine.h>
#include "loadlibrary.h"

void* load_lib(const char* libname){
    void* lib = loadlibrary(libname);
    if (lib == NULL) {
        fprintf(stderr, "Library %s loading failed\n", libname);
    }
    printf("Library %s loaded successfully\n", libname);
    return lib;
}

EXPORT void init() {
    printf("Core initialized\n");

    void* engine_lib = load_lib("engine");

    game g;
    init_externals(&g);

    bool hotReload = false;
    if(hotReload) {
        
    }

    while(g.play) {
        update_externals(&g);
        
        end_externals(&g);
    }
}
