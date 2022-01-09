def divide_2(dividend: int, divisor: int):
	dividend = bin(dividend)
	divisor = bin(divisor)
	dividend = str(dividend)[2:]
	divisor = str(divisor)[2:]

	print("dividend: ", dividend)
	print("divisor: ", divisor)


	i = 0
	j = 1
	# Long Division
	quotient = ""
	temp = 0
	while(j <= len(dividend)):
		val = dividend[i:j]
		# print("val: ",val)
		if(int(val,2) < int(divisor,2)):
			quotient = quotient + "0"
			j = j + 1
		else:
			quotient = quotient + "1"
			# if(int(val,2) - int(divisor,2)!=0):
			# 	dividend = bin( int(val,2) - int(divisor,2) )[2:] + dividend[j:]
			# 	temp = bin( int(val,2) - int(divisor,2) )[2:]
			# else:
			# 	dividend = dividend[j:]
			dividend = bin( int(val,2) - int(divisor,2) )[2:] + dividend[j:]
			temp = bin( int(val,2) - int(divisor,2) )[2:]
			# print("Dividend: ",dividend)
			i = 0
			j = len(temp)+1

	# print(quotient)
	# print(int(quotient,2))
	# print()
	return (int(quotient,2), int(dividend,2))
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        x = dividend
        y = divisor
        if(x<0 and y<0):
            x = -x
            y = -y
            (q, r) = divide_2(x, y)
            if q < 2147483647:
                return q
            else:
                return 2147483647
        elif(x<0 and y>0):
            x = -x
            y = y
            (q, r) = divide_2(x, y)
            # if(r!=0):
            # 	print(-q)
            # else:
            # 	print(-q)
            if -q > -2147483648:
                return -q
            else:
                return -2147483648
        elif(x>0 and y<0):
            x = x
            y = -y
            (q, r) = divide_2(x, y)
            # if(r!=0):
            # 	print(-q)
            # else:
            # 	print(-q)
            if -q > -2147483648:
                return -q
            else:
                return -2147483648
        else:
            (q, r) = divide_2(x, y)
            if q < 2147483647:
                return q
            else:
                return 2147483647
        return 0;
