#include <string.h>
#include <stdlib.h>
#include "object.h"
#include "mem.h"
#include "hashtbl.h"
#include "log.h"

static hashtbl* g_strtbl;

static object* internal_make_string(char *str) {
    object *obj;
    char *p;
    int len;
    
    if (str == NULL) {
        return NULL;
    }

    obj = alloc_object();
    /* do not use strdup, for a consistent way to do gc */
    len = strlen(str);
    p = sc_malloc(len + 1);
    if (p == NULL) {
        sc_log("%s", "no memory for string");
        exit(1);
    }
    strcpy(p, str);
    obj_sv(obj) = p;
    type(obj) = STRING;
    return obj;
}

int string_init(void) {
    g_strtbl = hashtbl_new(internal_make_string);
    if (g_strtbl == NULL) {
        sc_log("%s", "failed to initialize string table");
        return 1;
    }
    return 0;
}

void string_dispose(void) {
    hashtbl_dispose(g_strtbl);
}

object* make_string(char *str) {
    return hashtbl_insert(g_strtbl, str);
}

int is_string(object *obj) {
    return obj != NULL && type(obj) == STRING;
}

void string_free(object *obj) {
    char *str;

    if (obj == NULL) {
        return;
    }

    str = obj_sv(obj);
    hashtbl_remove(g_strtbl, obj, str);
    sc_free(str);
}

