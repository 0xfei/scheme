#include <stdio.h>

#define __LOCAL_SIZE 0x100

#define VARIABLE(n) [edx+n*4]

void __declspec(naked) do_ret()
{
	__asm {
		add esp, __LOCAL_SIZE
		pop ebp
		ret
	}
}

int __declspec(naked) call(void* f, int n, int* p)
{
	// ret address
	__asm {
		push ebp
		mov ebp, esp
		sub esp, __LOCAL_SIZE

		mov edx, p
		mov eax, [ebp+8]
		jmp eax
	}
}

int __declspec(naked) fibnaci(int n, int a, int b)
{
	__asm {
		mov eax, VARIABLE(0)
		cmp eax, 0
		jne __tailrec
		mov eax, VARIABLE(1)
		jmp do_ret
	}

__tailrec:
	__asm {
		mov ebx, VARIABLE(1)
		mov ecx, VARIABLE(2)
		dec eax
		add ebx, ecx
		mov VARIABLE(0), eax
		mov VARIABLE(1), ecx
		mov VARIABLE(2), ebx
		jmp [fibnaci]
	}
}

int tailrec_test()
{
	int p[3] = {100000000, 0, 1};

	int ans = call(fibnaci, 3, p);

	printf("%d\n", ans);

	return 0;
}
