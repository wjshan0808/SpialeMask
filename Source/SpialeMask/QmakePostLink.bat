::项目SpialeMask编译链接后执行脚本
::
::%1第一个参数值等价与 %~dp0脚本文件所在目录
::

::复制库文件到库目录
XCOPY "%1\..\..\Release\libSpialeMask.a" "%~dp0..\..\Library" /Y

::复制头文件到包含目录
XCOPY "%1\*.h" "%~dp0..\..\Include" /Y

