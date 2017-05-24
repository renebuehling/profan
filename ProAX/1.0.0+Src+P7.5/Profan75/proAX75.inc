
''$P+
$H proAX-internal.ph
$H proAX.ph
'--- Unit für ProAX, einem einfachen ActiveX-Tool für Profan
'--- René Bühling 5/2006, www.reboo.com
'--- Portierung für Profan 7.5+ René Bühling 6/2008, www.buehling.org

'Def @proAX_closeDLL(0) !"ProAX.dll", "closeDLL"
Def @proAX_fpCreate(1) !"ProAX.dll", "fpCreate"
Def @proAX_fpLoadMovie(3) !"ProAX.dll", "fpLoadMovie"
Def @proAX_fpIntnlCmd(4) !"ProAX.dll", "fpIntnlCmd"
Def @proAX_fpIntnlCmd2(8) !"ProAX.dll", "fpIntnlCmd2"
Def @proAX_ErrorFile(2) !"ProAX.dll", "ErrorFile"
Def @proAX_fpLoadFS(3) !"ProAX.dll", "loadFS"
Def @proAX_fpListen(2) !"ProAX.dll", "listen"
Def @proAX_supports(1) !"ProAX.dll", "supports"

declare proAX_dll%
'Unit initalisieren
proc proAX_begin
     'Parameter nicht möglich, da external nicht funzt (keine "Session"?)
     proAX_dll%=usedll("ProAX.dll")
endproc

'Registrieren
'proc proAX_reg
'     parameters
'endproc

'Unit deinitialisieren
proc proAX_end
     'proAX_closeDLL()
     freedll proAX_dll%
endproc

proc proAX_supportsFP
     parameters version&
     return proAX_supports(version&)
endproc


'CLASS FlashPlayer = Handle&, FlashPlayer@, Destroy@, LoadMovieNum@, Play@, Stop@, GetCurrentFrame@, \
'                    GotoAndStop@, GotoAndPlay@, GetLoop@, SetLoop@, GetMenu@, SetMenu@, \
'                    GetQuality@, SetQuality@, GetScale@, SetScale@, GetPlay@, GetTotalFrames@, \
'                    GetReadyState@, Pan@, Zoom@, GetPercentLoaded@, SetVar@, SetListener@, \
'                    GetNextFSCommand@, CountFSCommands@, FSCmd$(255), FSArgs$(255)

declare FP_Handle&, FP_FSCmd$, FP_FSArgs$
proc FP_FlashPlayer
     parameters parentHwnd&
     FP_Handle&=proAX_fpCreate(parentHwnd&)
endproc

proc FP_Destroy
     proAX_fpIntnlCmd(FP_Handle&,~PAX_FPFREE,0,0)
     FP_Handle&=0
endproc

proc FP_LoadMovieNum
     parameters url$, level%

     declare b#
     dim b#, 255
     String b#,0=url$
     proAX_fpLoadMovie(FP_Handle&,b#,level%)
     dispose b#
endproc

proc FP_Play
     proAX_fpIntnlCmd(FP_Handle&,~PAX_FPPLAY,0,0)
endproc

proc FP_Stop
     proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSTOP,0,0)
endproc

proc FP_GetCurrentFrame
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETFRAMENUM,0,0)
endproc

proc FP_GotoAndPlay
     parameters frame%
     FP_Stop
     proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETFRAMENUM,frame%,0)
     FP_Play
endproc

proc FP_GotoAndStop
     parameters frame%
     FP_Stop
     proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETFRAMENUM,frame%,0)
endproc

proc FP_GetLoop
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETLOOP,0,0)
endproc

proc FP_SetLoop
     parameters loop%
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETLOOP,loop%,0)
endproc

proc FP_GetMenu
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETMENU,0,0)
endproc

proc FP_SetMenu
     parameters mnu%
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETMENU,mnu%,0)
endproc

proc FP_GetQuality
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETQUALITY,0,0)
endproc

proc FP_SetQuality
     parameters q%
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETQUALITY,q%,0)
endproc

proc FP_GetScale
     return proAX_fpIntnlCmd(.Handle&,~PAX_FPGETSCALE,0,0)
endproc

proc FP_SetScale
     parameters s%
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETSCALE,s%,0)
endproc

proc FP_GetPlay
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETPLAY,0,0)
endproc

proc FP_GetTotalFrames
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETTOTALFRAMES,0,0)
endproc

proc FP_GetReadyState
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETREADYSTATE,0,0)
endproc

proc FP_Pan
     parameters fpx%, fpy%, pantype%

     if pantype%=~pax_fpPixel
        proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETPANPIXEL,fpx%,fpy%)
     else
        proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETPANPERCENT,fpx%,fpy%)
     endif
endproc

proc FP_Zoom
     parameters zs%
     proAX_fpIntnlCmd(FP_Handle&,~PAX_FPSETZOOM,zs%,0)
endproc

proc FP_GetPercentLoaded
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETPERCENTLOADED,0,0)
endproc

proc FP_SetVar
     parameters name$, value$

     declare b#,c#
     dim b#, 255
     dim c#, 255
     String b#,0=name$
     String c#,0=value$
     proAX_fpIntnlCmd2(FP_Handle&, ~PAX_FPSETVAR,b#,c#,0,0,0,0)
     dispose b#
     dispose c#
endproc

proc FP_SetListener
     parameters lisHan&
     proAX_fpListen(FP_Handle&, lisHan&)
endproc

proc FP_GetNextFSCommand
     declare b#,c#, erg$
     dim b#, 255
     dim c#, 255
     proAX_fpLoadFS(FP_Handle&, b#,c#)
     FP_FSCmd$=@string$(b#,0)
     FP_FSArgs$=@string$(c#,0)
     dispose b#
     dispose c#
     return FP_FSCmd$
endproc

proc FP_CountFSCommands
     return proAX_fpIntnlCmd(FP_Handle&,~PAX_FPGETFSCCOUNT,0,0)
endproc



