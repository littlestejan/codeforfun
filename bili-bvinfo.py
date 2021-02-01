# _*_ coding:utf-8 _*_  
#  
# @Version : 0.95
# @Time	: 2020/04/05
# @Author  : little_stejan
# @File	: bvinfo.py
# @Description:
#  对用户输入的b站视频地址进行信息获取并输出，最初制作目的只是为了小试身手。
#  该程序目前属于beta版本，仍在进行测试，bug只多不少。
#  更新记录：
#  Ver. 0.90 2020/03/24
#  第一个beta版本测试
#  Ver. 0.91 2020/03/25
#  对于团队创作类的视频，新增了显示团队名单的功能
#  新增显示视频投稿类型的功能
#  新增“获取时间”的显示，增强数据可读性
#  Ver. 0.92 2020/03/26
#  添加注释，添加简介（本文）
#  程序内部bug修复
#  Ver. 0.93 2020/03/28
#  将程序名称更改为bvinfo。其目的有三：
#  1.响应b站将av号全面升级至bv号的政策。由于b站目前保留了av号的相关功能，故软件
#    支持av号，bv号同时显示，且支持av号，bv号其一的输入以获得视频信息的功能。
#  2.bv可以是“bilibili video”的缩写，意指b站视频，所以文件名的全称大意即为
#    “b站视频信息获取”。该软件的用途，通过文件名便不言而喻。
#  3.缩短文件名。文件名的缩短对于大部分人来说重要性不必多言。利人利己，何乐而不为？
#  注释的添加和修改
#  （av升级为bv，爷的青春结束了）
#  Ver. 0.94 2020/03/30
#  新增是否为互动视频的检测，并修复了检测互动视频时出现的某些错误（P.S. 旧版本客户端
#  不能播放互动视频，会以cid号为99543100的视频进行替代，检测原理便是如此）
#  （未来的版本将对互动视频的详细信息做更多的获取和输出）
#  将所有作为缩进的空格改为大空格（即Tab）
#  Ver. 0.95 2020/04/05
#  支持开头为小写bv的BV号检测
#  bug修复
#  （未来获取互动视频详细信息的部分将以单独的程序提供，这个单独的程序既
#   可独立运行，也可在该软件内以import的形式导入并成为该软件的一部分）
#  （这个版本发布的同时本人亦以某知乎大佬在某个问题
#   https://www.zhihu.com/question/381784377/answer/1099438784
#   的回复中附上的代码为样本，制作了C++版本的本地av和bv互转的程序（本软件利用b站api
#   故需联网）原作者的代码可以在Python下直接运行，方法见链接内回复，本人不再在此阐述）
#
#  P.S. 本代码以WTFPL协议开源
#
import requests
import time

def get_api(type, id):
	print("正在获取视频信息，请稍后...")
	# 请求头
	headers = {
		"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8",
		"Accept-Encoding": "gzip, deflate, br",
		"Accept-Language": "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2",
		"Host": "api.bilibili.com",
		"Referer": "https://www.bilibili.com/",
		"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36",
	}
	# 刚刚获取的api
	if type == 1:
		api_url = "https://api.bilibili.com/x/web-interface/view?aid="+id # aid参数中的值开头不能带av
	elif type == 2:
		api_url = "https://api.bilibili.com/x/web-interface/view?bvid="+id # 而bvid则必须要带开头的BV
	# 开始请求
	restime = time.ctime() # 记录请求时间
	res = requests.get(api_url, headers=headers)
	online_dic = res.json()
	if online_dic['code'] != 0:
		print("视频信息获取失败，错误码%d" % online_dic['code'])
		return
	else:
		print("视频信息获取成功\n")
	# 输出视频的信息
	#print(online_dic)
	print("获取时间：%s" % restime)
	if type == 1:
		print("视频地址：https://www.bilibili.com/video/av%s" % id)
	elif type == 2:
		print("视频地址：https://www.bilibili.com/video/%s" % id)
	print("av号：av%d" % online_dic['data']['aid'])
	print("bv号：%s" % online_dic['data']['bvid'])
	print("视频标题：%s" % online_dic['data']['title'])
	print("视频分类：%s" % online_dic['data']['tname'])
	if online_dic['data']['copyright'] == 1:
		print("视频投稿类型：自制")
	elif online_dic['data']['copyright'] == 2:
		print("视频投稿类型：转载")
	print("视频封面地址：%s" % online_dic['data']['pic'])
	print("视频发布时间：%s" % time.ctime(online_dic['data']['pubdate']))
	print("视频简介：")
	print("%s\n" % online_dic['data']['desc'])
	print("视频播放量：%d" % online_dic['data']['stat']['view'])
	print("视频总弹幕数：%d" % online_dic['data']['stat']['danmaku'])
	print("视频点赞数：%d" % online_dic['data']['stat']['like'])
	print("视频点踩数（好像没啥用）：%d" % online_dic['data']['stat']['dislike'])
	print("视频投币数：%d" % online_dic['data']['stat']['coin'])
	print("视频收藏数：%d" % online_dic['data']['stat']['favorite'])
	print("视频转发数（有效转发）：%d\n" % online_dic['data']['stat']['share'])
	print("视频p数（集数）：%s" % len(online_dic['data']['pages']))
	#print("视频p数（集数）：%s" % online_dic['data']['videos']) 预留作后期互动视频检测之用
	for i in range(0,len(online_dic['data']['pages'])): # 遍历每一p中视频的详细信息
		print("第%dp：" % online_dic['data']['pages'][i]['page'])
		print(" 该p视频标题：%s" % online_dic['data']['pages'][i]['part'])
		if "stein_guide_cid" in online_dic['data'].keys() and online_dic['data']['stein_guide_cid'] == 99543100:
			print(" 是否为互动视频：是")
		else:
			print(" 是否为互动视频：否")
		print(" cid号：%d" % online_dic['data']['pages'][i]['cid'])
		print(" 弹幕地址（xml）：https://api.bilibili.com/x/v1/dm/list.so?oid=%d" % online_dic['data']['pages'][i]['cid'])
	if online_dic['data']['rights']['is_cooperation'] == 1:
		print("\n视频创作方式：团队")
		for i in range(0,len(online_dic['data']['staff'])): # 对创作团队中每个人的信息进行遍历并输出
			print("%s：%s" % (online_dic['data']['staff'][i]['title'],online_dic['data']['staff'][i]['name']))
			print(" 此用户uid：%d" % online_dic['data']['staff'][i]['mid'])
			print(" 此用户头像链接：%s" % online_dic['data']['staff'][i]['face'])
			print(" 此用户主页：https://space.bilibili.com/%d" % online_dic['data']['staff'][i]['mid'])
	elif online_dic['data']['rights']['is_cooperation'] == 0:
		print("\n视频创作方式：个人")
		print("up主昵称：%s" % online_dic['data']['owner']['name'])
		print("up主uid：%d" % online_dic['data']['owner']['mid'])
		print("up主头像链接：%s" % online_dic['data']['owner']['face'])
		print("up主主页：https://space.bilibili.com/%d" % online_dic['data']['owner']['mid'])
	

if __name__ == '__main__':
	print("bvinfo b站视频信息获取 Ver. 0.95")
	sid = input("请输入av或BV号（包括av或BV）：")
	if sid[:2] == "av":
		get_api(1,sid[2:]) # 只向函数中传入不带开头的av的部分
	elif (sid[:3] == "BV1" or sid[:3] == "bv1") and len(sid) == 12: # 所有的bv号若算上开头的BV，字符串长度均为12，即只有12位
		get_api(2,sid) # bv号则全部传入
	else:
		print("输入的内容有误")
	