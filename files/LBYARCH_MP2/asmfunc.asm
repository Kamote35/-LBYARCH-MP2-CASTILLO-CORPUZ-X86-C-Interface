; assembly part using x86-64 syntax

section .data
hour dq 1000.0 ; 1000M/H
second dq 3600.0 ; 1/3600 meter per seconds 
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
	MOVSD XMM3,XMM1
	VSUBSD XMM3,XMM3,XMM0 

	; XMM5 = (VFinal-Vinit) * hour
	MOVSD XMM4,[hour] ; XMM4 = hour
	VMULSD XMM5,XMM3,XMM4 

	; XMM7 = ((VFinal-Vinit) * hour) / second
	MOVSD XMM6, [second] ; XMM6 = second
	VDIVSD XMM7,XMM5,XMM6 

	; XMM9 = (((VFinal-Vinit) * hour) / second) / time
	MOVSD XMM8, XMM2
	VDIVSD XMM9, XMM7,XMM8

	; move the result to XMM0
	MOVSD XMM0,XMM9
	ret





	