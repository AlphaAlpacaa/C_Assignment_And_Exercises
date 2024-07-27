s = tf('s');
T = 0.001;
Gs = (s+2)/(s*s + 2*s + 5);
Gz = c2d(Gs, T);
num = cell2mat(Gz.Numerator);
den = cell2mat(Gz.Denominator);


% Simulate and write to file
fileID = fopen("system.txt", "w");
endTime = 5;
dataCount = endTime/T;
inputs = ones(dataCount, 2);
outputs = zeros(dataCount, 1);
fprintf(fileID, "%d\n", dataCount-2);
for i=3:dataCount
   outputs(i) = num(2)*inputs(i,1) + num(3)*inputs(i-1,2) - outputs(i-1)*den(2) - outputs(i-2)*den(3);
   fprintf(fileID, '%.2f %.2f\n',outputs(i), inputs(i));
end
%step(Gs);

%%
sysDeg = 2;
regressors = zeros(dataCount-2,4);
for i=1:dataCount-2
    for j=1:sysDeg
        index = i-j;
        if index < 1
            index = 1;
        end
        regressors(index,j) = inputs(index);
    end
    
    for j=1:sysDeg
        index = i-j-1;
        if index < 1
            index = 1;
        end
        regressors(index,j+sysDeg) = outputs(index);
    end
end

A = zeros(sysDeg*2, sysDeg*2);
for i=1:sysDeg*2
    for j=1:sysDeg*2
        col_1 = regressors(:,i);
        col_2 = regressors(:,j);
        A(i,j) = sum(col_1);dot(col_1, col_2);
    end
end
b = zeros(sysDeg*2,1);
for i=1:sysDeg*2
    b(i,1) = dot(outputs(3:end), regressors(:,i));
end

ls_coeffs = inv(A)*b;

%% LEast squares result

sym_inputs = ones(dataCount);
sym_outputs = zeros(dataCount, 1);

for i=3:dataCount
   sym_outputs(i) = ls_coeffs(1)*sym_inputs(i) + ls_coeffs(2)*sym_inputs(i-1) + ls_coeffs(3)*sym_outputs(i-1) + ls_coeffs(4)*sym_outputs(i-2);
   fprintf(fileID, '%.2f %.2f\n',outputs(i), inputs(i));
end
hold on
plot(sym_outputs);
plot(outputs);

 