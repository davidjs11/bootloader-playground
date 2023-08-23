[bits 16]
; this functions uses int 13,2 BIOS interrupt
; documentation: https://stanislavs.org/helppc/int_13-2.html

; read_disk.asm
; reads sectors from a disk and saves them into a buffer
; parameters:
;   'bx' - buffer address
;   'dh' - number of sectors to read
;   'dl' - drive index (boot-disk by initial value) (thanks BIOS!)
read_disk:
    pusha       ; push registers into stack

    push dx     ; we'll need dx later with new values from other regs

    ; set reading parameters (int 13.2)
    mov ah, 0x02    ; read-mode
    mov al, dh      ; number of sectors to read
    mov cl, 0x02    ; sector index
    mov ch, 0x00    ; track index (0x00 - 0x3FF)
    mov dh, 0x00    ; head index 

    ; read data from disk 
    int 0x13        ; call BIOS interrupt (read data)
    jc disk_error   ; if carry = 1 -> error

    ; check if all selected sectors have been read
    pop dx          ; recover 'dh' with number of sectors to read
    cmp al, dh      ; al now stores number of sectors read
    jne sectors_error ; if not all sectors have been read

    popa            ; recover registers
    ret             ; finish call


disk_error:
    ; print error
    mov bx, DISK_ERROR_MSG
    call print
    call newline

    ; print error code (see documentation)
    mov dh, al      ; 'dh': error code; 'dl': drive index
    call print_hex
    jmp $
    

sectors_error:
    ; print error message
    mov bx, SECTORS_ERROR_MSG
    call print
    jmp $


; error-message arrays
DISK_ERROR_MSG: db "Disk error!", 0x00
SECTORS_ERROR_MSG: db "Couldn't read all sectors!", 0x00
