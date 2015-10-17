print("Hello,Welcome to start this program.\nYou can choose \"+\",\"-\",\"*\",\"/\"! ")
while true do
	I = io.read()
	if I~="+" and I~="*" and I~="-" and I~="/"then
		break
	end
	print("The frist math:")
	F = io.read()
	print("The last math:")
	L=io.read()
	if I=="+" then
		print(F+L)
	else if I=="-" then
		print(F-L)
	else if I=="*" then
		print(F*L)
	else if I == "/" then
		if L == 0 then
			print("Error,dividend can't be 0!")
		else
			print(F/L)
		end
	end

end
end
end
print("You can choose \"+\",\"-\",\"*\",\"/\"! ")
end
