<<<<<<< HEAD
#pragma once
int transpile(const char* code);
=======
#ifndef TRANSPILER_H
#define TRANSPILER_H

#ifdef __cplusplus
extern "C" {
#endif

int transpileToBash(const char *filename);

#ifdef __cplusplus
}
#endif

#endif
>>>>>>> add-transpiler
