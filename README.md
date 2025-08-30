# my_terminal
- 开源，使用[Apache 2.0许可证](https://github.com/zghzd/my_terminal/blob/master/LICENSE.txt)  
- 允许:  
  - 商业使用  
  - 修改/衍生  
  - 分发  
  - 专利使用  
  - 私人使用  
- 注意，你需要:
  - 保留版权声明  
  - 标明修改内容  
  - 许可证副本分发
# 运行环境  
- 64位的Microsoft Windows系统，基于x64的处理器  
# release  
不论是程序主体还是程序组件，它们都需要一些指定的文件才能够正常运行，这里列出了程序主体运行时所需的文件，关于程序组件运行时所需的文件，请参阅文章中的对应部分。  
以下是程序主体运行时所需的文件：

- Visual C++运行库安装的所有文件  
> 这些文件是启动任何一个c++程序所必须的，这些文件的缺失会导致程序无法启动  

- mainconfig.config文件
> 程序的一些功能依赖于此文件中的内容，在发布的压缩包中可以找到此文件，如果此文件被修改，程序的一些操作可能超出预期，如果此文件丢失，程序的一些功能可能无法实现  

# 下载源代码并重新编译  
正如前文所说，你可以自由使用源代码。但是，如果你使用存储库中的**解决方案**和**项目**的配置文件，你需要注意:  
- 作者只对x64平台进行了配置，对于x86(x32)平台，我不建议你在这些平台上编译和运行，如果你执意要这么做，请自行调整配置  
- 请一定遵守版权声明和版权许可证的内容  
# 扩展功能  
> `扩展功能`是由`可选文件`实现的各项功能，若要实现扩展功能，必须拥有`扩展功能的支持组件`，以下是已有的扩展功能的介绍  

- 
>

# 指令  
> 用户与程序的交互由各种`指令`完成，以下是已有的指令的介绍  

- extended  
> 启动 扩展功能的支持组件，此组件是否允许启用由配置文件`mainconfig.config`决定  
> 若要使用此组件，需要拥有extendconfig.config文件  

- exit  
> 退出程序

- base64
> 进行base64编码或解码

- compare
> 以指定模式比较两个文件的差异  
> `stringtext`模式:以行为单位，比较两个文件的文本差异  
> 

# 启动参数  
> 以下是参数传递的介绍  

使用cmd命令行程序启动时:
  - 请先使用`cd /d`指令跳转至程序的工作目录  
  - 之后启动，使用指令`my_terminal.exe`可以直接启动程序，此时，参数使用程序预留的参数  
  - 如果使用参数，语法为`my_terminal.exe <null|debug>`  
> <release|debug>指定是(debug)否(null)启用程序的调试功能  
> 

# 版权声明
**除非特别说明，否则只有`已提交的代码`是开源的**，未提交的代码不在开源范围之内。  
  

   Copyright &copy; 2025 zghzd  
   
   Licensed under the Apache License, Version 2.0 (the "License");  
   you may not use this file except in compliance with the License.  
   You may obtain a copy of the License at  

       http://www.apache.org/licenses/LICENSE-2.0  

   Unless required by applicable law or agreed to in writing, software  
   distributed under the License is distributed on an "AS IS" BASIS,  
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  
   See the License for the specific language governing permissions and  
   limitations under the License.  