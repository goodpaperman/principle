
DictCompps.dll: dlldata.obj DictComp_p.obj DictComp_i.obj
	link /dll /out:DictCompps.dll /def:DictCompps.def /entry:DllMain dlldata.obj DictComp_p.obj DictComp_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DictCompps.dll
	@del DictCompps.lib
	@del DictCompps.exp
	@del dlldata.obj
	@del DictComp_p.obj
	@del DictComp_i.obj
