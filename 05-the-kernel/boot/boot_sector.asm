[bits 16]
[org 0x7C00]

KERNEL_OFFSET equ 0x1000    ; the memory offset our kernel will be located on


; --- boot-sector.asm -----------------------
; program that reads sectors from disk and loads the kernel

mov [BOOT_DRIVE], dl        ; BIOS saves boot drive index by default in 'dl'

mov bp, 0x9000              ; setup the stack
mov sp, bp

mov bx, MSG_REAL_MODE       ; print 16-bit mode message
call print
call newline

call load_kernel

call switch_pm

jmp $


; --- load kernel into memory ---------------
[bits 16]
load_kernel:
    mov bx, MSG_LOADING_KERNEL  ; print loading message
    call print
    call newline

    mov bx, KERNEL_OFFSET       ; memory address 
    mov dh, 15                  ; number of sectors
    mov dl, [BOOT_DRIVE]        ; drive index
    call read_disk              ; start reading disk 

    ret


; --- 32-bit program ------------------------
[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROTECTED_MODE ; print message
    call print_vga

    call KERNEL_OFFSET          ; start kernel

    jmp $


; --- data section --------------------------
; strings
MSG_REAL_MODE       db "Now in 16-bit real mode", 0x00
MSG_PROTECTED_MODE  db "Now in 32-bit protected mode", 0x00
MSG_LOADING_KERNEL  db "Now loading kernel...", 0x00

; current boot drive
BOOT_DRIVE          db 0x00


; --- gdt and routines ----------------------
%include "boot/gdt.asm"         ; defining global descriptor table
%include "boot/print.asm"       ; printing in 16bit real mode
%include "boot/print_hex.asm"   ; printing hex values in 16bit real mode
%include "boot/read_disk.asm"   ; reading disk sectors with BIOS calls
%include "boot/print_vga.asm"   ; printing in 32bit protected mode
%include "boot/switch_pm.asm"   ; switching to 32 bit protected mode


; --- mbt boot signature --------------------
times 510-($-$$) db 0x00
dw 0xAA55 ; magic last word 
