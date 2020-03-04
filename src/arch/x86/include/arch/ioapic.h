/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#ifndef __I386_ARCH_IOAPIC_H
#define __I386_ARCH_IOAPIC_H

#define IO_APIC_ADDR	0xfec00000
#define VIO_APIC_VADDR	((u8 *)IO_APIC_ADDR)
#define IO_APIC_INTERRUPTS 24

#ifndef __ACPI__

#include <stdint.h>

#define ALL		(0xff << 24)
#define NONE		(0)
#define INT_DISABLED	(1 << 16)
#define INT_ENABLED	(0 << 16)
#define TRIGGER_EDGE	(0 << 15)
#define TRIGGER_LEVEL	(1 << 15)
#define POLARITY_HIGH	(0 << 13)
#define POLARITY_LOW	(1 << 13)
#define PHYSICAL_DEST	(0 << 11)
#define LOGICAL_DEST	(1 << 11)
#define ExtINT		(7 << 8)
#define NMI		(4 << 8)
#define SMI		(2 << 8)
#define INT		(1 << 8)

u32 io_apic_read(void *ioapic_base, u32 reg);
void io_apic_write(void *ioapic_base, u32 reg, u32 value);
void set_ioapic_id(void *ioapic_base, u8 ioapic_id);
void setup_ioapic(void *ioapic_base, u8 ioapic_id);
void clear_ioapic(void *ioapic_base);
#endif

#endif
