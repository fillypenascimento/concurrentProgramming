	.file	"1.1.1.c"
	.globl	contador
	.bss
	.align 4
	.type	contador, @object
	.size	contador, 4
contador:
	.zero	4
	.text
	.globl	incrementos
	.type	incrementos, @function
incrementos:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	contador(%rip), %eax
	addl	$1, %eax
	movl	%eax, contador(%rip)
	addl	$1, -4(%rbp)
.L2:
	cmpl	$99, -4(%rbp)
	jle	.L3
	movl	$0, %edi
	call	pthread_exit
	.cfi_endproc
.LFE2:
	.size	incrementos, .-incrementos
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$10, -60(%rbp)
	movl	-60(%rbp), %eax
	cltq
	subq	$1, %rax
	movq	%rax, -40(%rbp)
	movl	-60(%rbp), %eax
	cltq
	movq	%rax, %rsi
	movl	$0, %edi
	movl	-60(%rbp), %eax
	cltq
	movq	%rax, %rdx
	movl	$0, %ecx
	movl	-60(%rbp), %eax
	cltq
	salq	$3, %rax
	leaq	7(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$7, %rax
	shrq	$3, %rax
	salq	$3, %rax
	movq	%rax, -32(%rbp)
	movq	$0, -56(%rbp)
	jmp	.L5
.L6:
	movq	-56(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	$0, %ecx
	movl	$incrementos, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create
	addq	$1, -56(%rbp)
.L5:
	movl	-60(%rbp), %eax
	cltq
	cmpq	-56(%rbp), %rax
	jg	.L6
	movq	$0, -48(%rbp)
	jmp	.L7
.L8:
	movq	-32(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	(%rax,%rdx,8), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join
	addq	$1, -48(%rbp)
.L7:
	movl	-60(%rbp), %eax
	cltq
	cmpq	-48(%rbp), %rax
	jg	.L8
	movl	contador(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	%rbx, %rsp
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail
.L10:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
