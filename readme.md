# DLC32

## 描述

- 暂无

## 需要修复的问题

- 从屏幕中读取.nc文件进行雕刻，得到的效果不佳
- 图形界面在弹窗后没有失能控件，导致出现弹窗后仍能进行触摸
- 文件读取列表中，在最后一页返回时候，会出现闪退

## 

# 修改记录

## data:2021-04-22

- 修改电机运动模式为\#define DEFAULT_STEPPER ST_I2S_STATIC

- 修改激光输出频率为1000
- 修改激光最大S值为1000
- 修改SD卡读写速度为4000000Hz



## data:2021-04-25

- 修复CoreXY机器重印的问题
- 修复打印效果问题

机型：XY

1、修复硬限位触发后停止的问题

2、修复屏幕触发硬限位回零失败的问题

3、硬件回零速度默认写死800

4、修复<使用上位机在移动过程中触碰限位会使上位机停止，复位上位机后正常>的问题

5、修复<屏幕上硬件限位回零的效果不对，点YES会停止回零>

------------------------------------------------------------------------------------------------------------------

1、修复<快速点击导致的问题，加入弹窗提示>

2、修改回零时弹窗方式

---------------------------

1、修改主页功率显示

2、修改文件目录显示

3、加入限位提示（需要测试）

------------------

1、修复<文件列表能重复选择的问题>

2、修复由于限位导致黑屏重启的的问题

3、修复激光连按不能正常打开/关闭的问题

-------

## data:2021-05-21

1、优化读卡

2、修复<文件名前面带有’/‘>

3、增加巡边功能

4、优化打印中的限位检测

-----

1、打印中页面禁用软限位检测

----

1、修复软限位误触发问题

2、修复打印中突然停止的问题

3、修复巡边错位的问题

4、修复巡边没有激光的问题

----

1、修复<描边点击返回后  机器无法操作>

2、修复<描边大小会出现与图片不符合的情况，但是雕刻正常>

3、修复联机问题



-------

## data:2021-05-26

1、修复cancel拼写错误

2、取消描边过程中能够点击打印

3、修复上位机不能定位的问题

