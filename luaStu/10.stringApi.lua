--string 常用api
str1 = "abcd";
str2 = string.upper(str1); -- 转大写ABCD
print(str2);
print(string.lower(str2)); --转小写abcd

print(string.len(str1)); --字符长度4
print(string.len("你干嘛？")); --12

print(string.reverse(str1));--dcba

print("abcd".."xyz"..str2..str1..123 ..234); --number在连接符左边，后面要空格

str4 = "ancd123";
print(string.sub(str4,5,7)); --截取字符串 从下标5截取到7 -- 123
print(string.sub(str4,-4,-1)); -- 》   -4 -3 -2 -1负数从右往左读 从-1开始 d123

test = "kda";
str5 = "ackda123";

print(string.find(str5,test)); --返回该字符串的初始下标位置和结尾位置
print(string.find(str5,"ck",1)); --指定位置查找 

str2 = "abcd1234";
print(string.gsub(str2,"cd","CE")); -- 替换子串 返回替换后的字符串和 替换的次数 （str2,"cd","CE",2）2是局限于两次 abCE1234

print(string.char(67)); --ASCII数值 转 字符
print(string. byte("acv",1,3)) --字符转ASCII数值