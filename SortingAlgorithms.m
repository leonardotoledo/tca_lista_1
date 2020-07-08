clc;
clear all

%Tamanho inicial dos vetores
size=1000000;

%geração de números aleatórios
rNumbers=randi([0, size], 1, size);
%Geração de números crescentes
cNumbers= linspace(0, size, size);
%Geração de números decrescentes
dNumbers= linspace(size, 0, size);

%criação de cópias dos vetores
Copy=[];
for i=1:4
    Copy(i).rNumbers=rNumbers;
    Copy(i).cNumbers=cNumbers;
    Copy(i).dNumbers=dNumbers;
end
%Execução dos algorítimos de ordenamento
for i=1:4
    
    if (i==1)
        tic
        Copy(i).rNumbers=selection_sort(Copy(i).rNumbers);
        Copy(i).rETimeSS=toc;
        
        tic
        Copy(i).cNumbers=selection_sort(Copy(i).cNumbers);
        Copy(i).cETimeSS=toc;
        
        tic
        Copy(i).dNumbers=selection_sort(Copy(i).dNumbers);
        Copy(i).dETimeSS=toc;
        
    elseif (i==2)
        
        tic
        Copy(i).rNumbers=merge_sort(Copy(i).rNumbers);
        Copy(i).rETimeMS=toc;
        
        tic
        Copy(i).cNumbers=merge_sort(Copy(i).cNumbers);
        Copy(i).cETimeMS=toc;
        
        tic
        Copy(i).dNumbers=merge_sort(Copy(i).dNumbers);
        Copy(i).dETimeMS=toc;
                
    elseif (i==3)
        
        tic
        Copy(i).rNumbers=quick_sort(Copy(i).rNumbers, 1, length(Copy(i).rNumbers));
        Copy(i).rETimeQS=toc;
        
        tic
        Copy(i).cNumbers=quick_sort(Copy(i).cNumbers, 1, length(Copy(i).cNumbers));
        Copy(i).cETimeQS=toc;
        
        tic
        Copy(i).dNumbers=quick_sort(Copy(i).dNumbers, 1, length(Copy(i).dNumbers));
        Copy(i).dETimeQS=toc;
    elseif(i == 4)
        
        tic
        Copy(i).rNumbers=insertion_sort(Copy(i).rNumbers);
        Copy(i).rETimeIS=toc;
        
        tic
        Copy(i).cNumbers=insertion_sort(Copy(i).cNumbers);
        Copy(i).cETimeIS=toc;
        
        tic
        Copy(i).dNumbers=insertion_sort(Copy(i).dNumbers);
        Copy(i).dETimeIS=toc;
    end
end

function copy=selection_sort(copy)
m=0;
aux=0;
for i=1:length(copy)-1
    m=i;
    for j=i+1:length(copy)
        if (copy(j)<copy(i))
            m=j;
        end
    end
    aux=copy(i);
    copy(i)=copy(m);
    copy(m)=aux;
end
end

function copy=merge_sort(copy)

size = length(copy);

if (size < 2)
    
    copy=copy;    
else
    %Pega a metade do vetor
    m = floor(.5*size);
    
    %fazendo a divisão do vetor e aplicando merge sort recursivamente
    l=merge_sort(copy(1:m));
    r=merge_sort(copy(m+1:size));
    
    nl=length(l);
    nr=length(r);

    i=1;
    j=1;
    
    for k=1:(nl + nr)
        if (i > nl)
            copy(k) = r(j);
            j=j+1;            
        elseif (j > nr)            
            copy(k) = l(i);
            i=i+1;            
        elseif (l(i)<= r(j))         
            copy(k)=l(i);
            i=i+1;                
        else
            copy(k)=r(j);
            j=j+1;
        end            
    end
end
end

function copy=quick_sort(copy, left, right)

if ( right> left)
    v=copy(floor((left+right)/2));
    i=left;
    j=right;
    aux=0;
    
    while(j>=i)
        while (copy(i)< v && right>i)
            i=i+1;
        end
        while (copy(i)> v && j>left)
            j=j-1;
        end
        if (i<=j)
            aux= copy(i);
            copy(i)=copy(j);
            copy(j)=aux;
            i=i+1;
            j=j-1;
        end
    end
    if (j > left)
        copy=quick_sort(copy, left, j);
    end
    if (i<right)
        copy=quick_sort(copy, i, right);
    end
end
j=0;
v=0;
aux=0;
for i=2:length(copy)
    v=copy(i);
    j=i;
    
    while (copy(j-1)>v && j>2)
        aux=copy(j);
        copy(j)=copy(j-1);
        copy(j-1)=aux;
        j=j-1;
    end
    
    copy(j)=v;
end
end

function copy=insertion_sort(copy)
j=0;
v=0;
aux=0;
for i=2:length(copy)
    v=copy(i);
    j=i;
    
    while (copy(j-1)>v && j>2)
        aux=copy(j);
        copy(j)=copy(j-1);
        copy(j-1)=aux;
        j=j-1;
    end
    
    copy(j)=v;
end
end
