.global reset
.section .vectors
.word 0x20001000
.word reset                     /*reset handler*/
.word reset                     /*NMI*/
.word reset                     /*hard fault*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/
.word reset                     /*etc handler*/

.section .text
.thumb_func
reset:
    bl main


