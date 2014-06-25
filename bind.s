[BITS 64]

global  _call:function



struc list
    .val:       resq 1
    .next:      resq 1
endstruc

%define         reg0    rdi
%define         reg1    rsi
%define         reg2    rdx
%define         reg3    rcx
%define         reg4    r8
%define         reg5    r9



section .text
_call:
        push    rbp
        mov     rbp, rsp

        push    rdi
        mov     rax, rsi

%assign i       0
%rep    6
        cmp     rax, 0
        je      .call
        mov     reg%[i], [rax+list.val]
        mov     rcx, [rax+list.next]
        mov     rax, rcx
%assign i       i+1
%endrep

    .call:
        pop     rax                     ; pointer of function
        call    rax

        leave
        ret

