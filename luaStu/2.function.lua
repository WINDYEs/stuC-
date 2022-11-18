function func1()
    print("func1");
end

func1();

function func2(a,b,c)
    print("func2 ", a , b , c);
end
func2(1,2,3);
function func3(a,b,c)
    return a,b,c, "eee",'123';
    
end
print(func3(4,true,"STRING"));--打印返回的数据

--可变参
function func4(...)
    
end

--函数当右值 把匿名函数赋值给变量
sum1 =  function (a,b)
    return a - b;
end
print(sum1(1,2));

sum2 = sum1;
print(sum2(1122 , 122));

--当其他函数的参数
function func5(functionN,a,b)
    return functionN(a,b);
end

print(func5(sum1,123,23));

function func6(a,b)
    print(a,b);
end

func5(func6("jack", "rose"));
