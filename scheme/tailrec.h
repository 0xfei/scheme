#ifndef _TAIL_REC_H
#define _TAIL_REC_H

int __declspec(naked) call(void* f, int n, int* p);
void __declspec(naked) do_ret();

#endif
