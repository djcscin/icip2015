function artificial2013(bordas)

arquivos = dir('artificial-icassp2013/*.pbm');
numArquivos = length(arquivos);
for j=1:numArquivos
    image = imread(['artificial-icassp2013/' arquivos(j).name]);
    image(1:bordas, :) = true;
    image(:, 1:bordas) = true;
    image(end-bordas+1:end, :) = true;
    image(:, end-bordas+1:end) = true;
    tituloArq = arquivos(j).name;
    imwrite(image, ['artificial2013/', tituloArq], 'Encoding', 'rawbits');
end
fclose('all');
