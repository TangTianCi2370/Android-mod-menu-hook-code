public virtual void CheckGrade(Note note, ref Note.eGradeLevel level, MusicScoreKey key, bool forceMiss = False, int skillIconId = -1) { }

il2cpp:000000000135845C A1 02 40 B9                   LDR             W1, [X21]
il2cpp:0000000001358460 E2 43 02 91                   ADD             X2, SP, #0x120+var_90
il2cpp:0000000001358464 E0 03 13 AA                   MOV             X0, X19
il2cpp:0000000001358468 E3 03 1F 2A                   MOV             W3, WZR
il2cpp:000000000135846C FF 93 00 B9                   STR             WZR, [SP,#0x120+var_90]
il2cpp:0000000001358470 0A 2C 00 94                   BL              sub_1363498
il2cpp:0000000001358470
il2cpp:0000000001358474 20 06 00 36                   TBZ             W0, #0, loc_1358538 // compare note to nop
il2cpp:0000000001358474
il2cpp:0000000001358478 E8 03 1E 32                   MOV             W8, #4   // the 4 to perfect
il2cpp:000000000135847C A8 02 00 B9                   STR             W8, [X21]
il2cpp:0000000001358480 60 32 42 F9                   LDR             X0, [X19,#0x460]
il2cpp:0000000001358484 80 68 00 B4                   CBZ             X0, loc_1359194
il2cpp:0000000001358484
il2cpp:0000000001358488 08 00 40 F9                   LDR             X8, [X0]
il2cpp:000000000135848C 09 85 57 A9                   LDP             X9, X1, [X8,#0x178]
il2cpp:0000000001358490 20 01 3F D6                   BLR             X9

Perfect = 4,;E8 03 1E 32 
Great = 3;   68 00 80 52
Nice = 2;    E8 03 1F 32
