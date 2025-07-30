; assembly part using x86-64 syntax

section .data
hour dd 1000.0 ; 1000M/H
second dd 3600.0 ; 1/3600 meter per seconds 
section .text
bits 64
default rel 

global computeAcceleration
extern printf

computeAcceleration:
	; xmm0 = Vinit
	; xmm1 = Vfinal
	; xmm2 = time

	; XMM3 = Vfinal - Vinit 
	MOVSS XMM3,XMM1
	VSUBSS XMM3,XMM3,XMM0 

	; XMM5 = (VFinal-Vinit) * hour
	MOVSS XMM4,[hour] ; XMM4 = hour
	VMULSS XMM5,XMM3,XMM4 

	; XMM7 = ((VFinal-Vinit) * hour) / second
	MOVSS XMM6, [second] ; XMM6 = second
	VDIVSS XMM7,XMM5,XMM6 

	; XMM9 = (((VFinal-Vinit) * hour) / second) / time
	MOVSS XMM8, XMM2
	VDIVSS XMM9, XMM7,XMM8

	; move the result to RAX (convert it to integer))
	CVTSS2SI RAX,XMM9 ; convert to integer
	ret





	