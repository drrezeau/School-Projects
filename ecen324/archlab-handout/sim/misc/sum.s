	.file	"sum.c"
	.text
.globl sum_list
	.type	sum_list, @function
sum_list:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	$0, %eax
	testl	%edx, %edx
	je	.L3
.L6:
	addl	(%edx), %eax
	movl	4(%edx), %edx
	testl	%edx, %edx
	jne	.L6
.L3:
	popl	%ebp
	ret
	.size	sum_list, .-sum_list
.globl rsum_list
	.type	rsum_list, @function
rsum_list:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %ebx
	movl	$0, %eax
	testl	%ebx, %ebx
	je	.L10
	movl	4(%ebx), %eax
	movl	%eax, (%esp)
	call	rsum_list
	addl	(%ebx), %eax
.L10:
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.size	rsum_list, .-rsum_list
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %eax
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-16)"
	.section	.note.GNU-stack,"",@progbits
