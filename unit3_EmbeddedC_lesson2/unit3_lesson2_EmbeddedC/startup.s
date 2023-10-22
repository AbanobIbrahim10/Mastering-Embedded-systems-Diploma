.global reset
reset:
ldr sp,=stack_pointer
bl main
