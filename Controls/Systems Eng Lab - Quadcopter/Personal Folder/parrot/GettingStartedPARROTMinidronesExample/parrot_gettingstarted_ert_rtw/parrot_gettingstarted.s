	.arch armv5te
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"parrot_gettingstarted.c"
	.comm	cmd_inport,36,4
	.comm	sensor_inport,2496,8
	.comm	motors_outport,16,4
	.comm	flag_outport,1,1
	.comm	parrot_gettingstarted_Y,20,4
	.comm	parrot_gettingstarted_M_,48,8
	.global	parrot_gettingstarted_M
	.section	.data.rel.ro,"aw",%progbits
	.align	2
	.type	parrot_gettingstarted_M, %object
	.size	parrot_gettingstarted_M, 4
parrot_gettingstarted_M:
	.word	parrot_gettingstarted_M_
	.global	__aeabi_dmul
	.global	__aeabi_dadd
	.global	__aeabi_f2d
	.global	__aeabi_dcmplt
	.global	__aeabi_dcmpgt
	.global	__aeabi_d2f
	.global	__aeabi_dcmpeq
	.global	__aeabi_dsub
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Simulation finished\000"
	.global	__aeabi_ui2d
	.text
	.align	2
	.global	parrot_gettingstarted_step
	.type	parrot_gettingstarted_step, %function
parrot_gettingstarted_step:
	.fnstart
.LFB0:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, fp, lr}
	.save {r4, r5, r6, r7, fp, lr}
.LCFI0:
	.setfp fp, sp, #20
	add	fp, sp, #20
.LCFI1:
	.pad #16
	sub	sp, sp, #16
.LCFI2:
	ldr	r4, .L20
.LPIC0:
	add	r4, pc, r4
	mov	r3, #0
	str	r3, [fp, #-32]
	b	.L2
.L10:
	ldr	r3, [fp, #-32]
	add	r2, r3, #4
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	mov	r2, r2, asl #3
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #144]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r2, [fp, #-32]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	mov	r2, r2, asl #3
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #136]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, [fp, #-32]
	add	r2, r3, #8
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	mov	r2, r2, asl #3
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #152]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, [fp, #-32]
	add	r2, r3, #12
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	mov	r2, r2, asl #3
	add	r3, r2, r3
	ldrd	r0, [r3]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #160]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrd	r2, [r3, #128]
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [fp, #-28]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #168]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-28]
	bl	__aeabi_dcmplt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L3
.L4:
	mov	r3, #1
	mov	r5, r3
.L3:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L5
	ldr	r2, [fp, #-32]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldr	r1, [r3, #168]	@ float
	ldr	r3, .L20+8
	ldr	r3, [r4, r3]
	str	r1, [r3, r2, asl #2]	@ float
	b	.L6
.L5:
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #172]	@ float
	mov	r0, r3
	bl	__aeabi_f2d(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r2
	mov	r1, r3
	ldrd	r2, [fp, #-28]
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L7
.L8:
	mov	r3, #1
	mov	r5, r3
.L7:
	and	r3, r5, #255
	cmp	r3, #0
	beq	.L9
	ldr	r2, [fp, #-32]
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldr	r1, [r3, #172]	@ float
	ldr	r3, .L20+8
	ldr	r3, [r4, r3]
	str	r1, [r3, r2, asl #2]	@ float
	b	.L6
.L9:
	ldr	r5, [fp, #-32]
	ldrd	r0, [fp, #-28]
	bl	__aeabi_d2f(PLT)
	mov	r2, r0
	ldr	r3, .L20+8
	ldr	r3, [r4, r3]
	str	r2, [r3, r5, asl #2]	@ float
.L6:
	ldr	r2, [fp, #-32]
	ldr	r1, [fp, #-32]
	ldr	r3, .L20+8
	ldr	r3, [r4, r3]
	ldr	r1, [r3, r1, asl #2]	@ float
	ldr	r3, .L20+12
	ldr	r3, [r4, r3]
	str	r1, [r3, r2, asl #2]	@ float
	ldr	r3, [fp, #-32]
	add	r3, r3, #1
	str	r3, [fp, #-32]
.L2:
	ldr	r3, [fp, #-32]
	cmp	r3, #3
	ble	.L10
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrb	r3, [r3, #178]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L11
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #177]	@ zero_extendqisi2
	ldr	r3, .L20+16
	ldr	r3, [r4, r3]
	strb	r2, [r3, #0]
	b	.L12
.L11:
	ldr	r3, .L20+4
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #176]	@ zero_extendqisi2
	ldr	r3, .L20+16
	ldr	r3, [r4, r3]
	strb	r2, [r3, #0]
.L12:
	ldr	r3, .L20+16
	ldr	r3, [r4, r3]
	ldrb	r2, [r3, #0]	@ zero_extendqisi2
	ldr	r3, .L20+12
	ldr	r3, [r4, r3]
	strb	r2, [r3, #16]
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #4]
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	add	r3, r3, #8
	mov	r0, r2
	mov	r1, r3
	bl	rt_UpdateTXYLogVars(PLT)
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #32]
	mov	r0, r2
	mov	r1, r3
	mov	r2, #0
	mov	r3, #-1090519040
	add	r3, r3, #15728640
	bl	__aeabi_dcmpeq(PLT)
	mov	r3, r0
	cmp	r3, #0
	bne	.L13
.L19:
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r0, [r3, #32]
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #8]
	bl	__aeabi_dsub(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #8]
	mov	r0, r2
	mov	r1, r3
	mov	r2, #0
	mov	r3, #1015021568
	add	r3, r3, #3145728
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r1, #0
	mov	r5, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dcmpgt(PLT)
	mov	r3, r0
	cmp	r3, #0
	beq	.L15
.L16:
	mov	r3, #1
	mov	r5, r3
.L15:
	and	r3, r5, #255
	eor	r3, r3, #1
	and	r3, r3, #255
	cmp	r3, #0
	beq	.L13
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L20+24
	add	r2, r4, r2
	str	r2, [r3, #0]
.L13:
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #16]
	add	r2, r2, #1
	str	r2, [r3, #16]
	ldr	r3, [r3, #16]
	cmp	r3, #0
	bne	.L17
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #20]
	add	r2, r2, #1
	str	r2, [r3, #20]
.L17:
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r5, [r3, #0]
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #16]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #24]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r6, r2
	mov	r7, r3
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #20]
	mov	r0, r3
	bl	__aeabi_ui2d(PLT)
	ldr	r3, .L20+20
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #24]
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r2
	mov	r1, r3
	mov	r2, #0
	mov	r3, #1090519040
	add	r3, r3, #15728640
	bl	__aeabi_dmul(PLT)
	mov	r2, r0
	mov	r3, r1
	mov	r0, r6
	mov	r1, r7
	bl	__aeabi_dadd(PLT)
	mov	r2, r0
	mov	r3, r1
	strd	r2, [r5, #8]
	sub	sp, fp, #20
	ldmfd	sp!, {r4, r5, r6, r7, fp, pc}
.L21:
	.align	2
.L20:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+8)
	.word	parrot_gettingstarted_P(GOT)
	.word	motors_outport(GOT)
	.word	parrot_gettingstarted_Y(GOT)
	.word	flag_outport(GOT)
	.word	parrot_gettingstarted_M(GOT)
	.word	.LC0(GOTOFF)
.LFE0:
	.fnend
	.size	parrot_gettingstarted_step, .-parrot_gettingstarted_step
	.section	.rodata
	.align	2
.LC1:
	.ascii	"tout\000"
	.align	2
.LC2:
	.ascii	"\000"
	.align	2
.LC3:
	.ascii	"rt_\000"
	.text
	.align	2
	.global	parrot_gettingstarted_initialize
	.type	parrot_gettingstarted_initialize, %function
parrot_gettingstarted_initialize:
	.fnstart
.LFB1:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, fp, lr}
	.save {r4, fp, lr}
.LCFI3:
	.setfp fp, sp, #8
	add	fp, sp, #8
.LCFI4:
	.pad #28
	sub	sp, sp, #28
.LCFI5:
	ldr	r4, .L24
.LPIC1:
	add	r4, pc, r4
	mov	r0, #8
	bl	rt_InitInfAndNaN(PLT)
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #48
	bl	memset(PLT)
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r1, [r3, #0]
	mov	r2, #0
	mov	r3, #1073741824
	add	r3, r3, #5832704
	strd	r2, [r1, #32]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r1, [r3, #0]
	mov	r2, #0
	mov	r3, #1069547520
	add	r3, r3, #3145728
	strd	r2, [r1, #24]
	ldr	r3, .L24+8
	add	r3, r4, r3
	mov	r2, #0
	str	r2, [r3, #68]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r2, .L24+8
	add	r2, r4, r2
	str	r2, [r3, #4]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #48]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #4]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L24+12
	add	r2, r4, r2
	str	r2, [r3, #28]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L24+16
	add	r2, r4, r2
	str	r2, [r3, #32]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L24+16
	add	r2, r4, r2
	str	r2, [r3, #36]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L24+20
	add	r2, r4, r2
	str	r2, [r3, #24]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #4
	str	r2, [r3, #12]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #16]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #1
	str	r2, [r3, #20]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	ldr	r2, .L24+16
	add	r2, r4, r2
	str	r2, [r3, #40]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #52]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	r3, [r3, #4]
	mov	r2, #0
	str	r2, [r3, #8]
	ldr	r3, .L24+24
	ldr	r3, [r4, r3]
	ldr	r2, .L24+28	@ float
	str	r2, [r3, #0]	@ float
	ldr	r3, .L24+24
	ldr	r3, [r4, r3]
	ldr	r2, .L24+28	@ float
	str	r2, [r3, #4]	@ float
	ldr	r3, .L24+24
	ldr	r3, [r4, r3]
	ldr	r2, .L24+28	@ float
	str	r2, [r3, #8]	@ float
	ldr	r3, .L24+24
	ldr	r3, [r4, r3]
	ldr	r2, .L24+28	@ float
	str	r2, [r3, #12]	@ float
	ldr	r3, .L24+32
	ldr	r3, [r4, r3]
	mov	r2, #0
	strb	r2, [r3, #0]
	ldr	r3, .L24+36
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #36
	bl	memset(PLT)
	ldr	r3, .L24+40
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #2496
	bl	memset(PLT)
	ldr	r3, .L24+44
	ldr	r3, [r4, r3]
	mov	r0, r3
	mov	r1, #0
	mov	r2, #20
	bl	memset(PLT)
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldr	ip, [r3, #4]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r0, [r3, #32]
	ldr	r3, .L24+4
	ldr	r3, [r4, r3]
	ldr	r3, [r3, #0]
	ldrd	r2, [r3, #24]
	ldr	lr, .L24+4
	ldr	lr, [r4, lr]
	ldr	lr, [lr, #0]
	strd	r0, [sp]
	strd	r2, [sp, #8]
	str	lr, [sp, #16]
	mov	r0, ip
	mov	r2, #0
	mov	r3, #0
	bl	rt_StartDataLoggingWithStartTime(PLT)
	sub	sp, fp, #8
	ldmfd	sp!, {r4, fp, pc}
.L25:
	.align	2
.L24:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC1+8)
	.word	parrot_gettingstarted_M(GOT)
	.word	rt_DataLoggingInfo.3005(GOTOFF)
	.word	.LC1(GOTOFF)
	.word	.LC2(GOTOFF)
	.word	.LC3(GOTOFF)
	.word	motors_outport(GOT)
	.word	0
	.word	flag_outport(GOT)
	.word	cmd_inport(GOT)
	.word	sensor_inport(GOT)
	.word	parrot_gettingstarted_Y(GOT)
.LFE1:
	.fnend
	.size	parrot_gettingstarted_initialize, .-parrot_gettingstarted_initialize
	.align	2
	.global	parrot_gettingstarted_terminate
	.type	parrot_gettingstarted_terminate, %function
parrot_gettingstarted_terminate:
	.fnstart
.LFB2:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	.save {fp}
.LCFI6:
	.setfp fp, sp, #0
	add	fp, sp, #0
.LCFI7:
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.LFE2:
	.fnend
	.size	parrot_gettingstarted_terminate, .-parrot_gettingstarted_terminate
	.local	rt_DataLoggingInfo.3005
	.comm	rt_DataLoggingInfo.3005,72,4
	.ident	"GCC: (Sourcery G++ Lite 2009q3-67) 4.4.1"
	.section	.note.GNU-stack,"",%progbits
