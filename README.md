Максимов Вячеслав 

3441102/00301


Task 1.9
Реализовать интерфейс для класса кодеров
Методы интерфейса:
std::vector<uint8_t> Encode(std::vector<uint8_t> const& data);
Реализовать 2 класса для кодирования один для кода хэмминга (7,4), второй на выбор
Входные и выходные данные представляются в виде битового потока т.е. один байт несет в себе 8 бит, при количестве бит не кратных байту последние биты заполняются 0. Кодировать необходимо именно биты!
В данном задании рассматривать uint8_t как набор из 8 битов, а не как число.



s=de2bi([240, 127, 255, 0, 90],8)
s2=bi2de(s);

out=zeros(size(s,1),14);
for i=1:size(s,1)
    a1=mod(sum(s(i,[1,3,4])),2);
    a2=mod(sum(s(i,[1,2,3])),2);
    a3=mod(sum(s(i,[2,3,4])),2);
    out(i,1:7)=[a1 a2 a3 s(i,[1:4])];
    
    a1=mod(sum(s(i,[5,7,8])),2);
    a2=mod(sum(s(i,[5,6,7])),2);
    a3=mod(sum(s(i,[6,7,8])),2);
    out(i,8:14)=[a1 a2 a3 s(i,[5:8])]
end

out=out';
 out=out(1:end)

for i=1:length(out)/8
    res(i)=bi2de(out(1+8*(i-1):8*(i)))
end
res
