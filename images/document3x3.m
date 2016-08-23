function document3x3(bordas)

delete('document3x3/*.pbm');        
arquivos = dir('document/*.tif');
numArquivos = length(arquivos);
for j=1:numArquivos
	image = imread(['document/' arquivos(j).name]);
    [height width] = size(image);
    h = height + mod(height,2) + bordas;
    w = width + mod(width,2) + bordas;
    I = true(bordas + 3*h, bordas + 3*w);
    for ii=0:2
        iii = ii*h+bordas;
        for jj=0:2
            jjj = jj*w+bordas;
            I( 1+iii:height+iii, 1+jjj:width+jjj ) = image;
        end
    end
	tituloArq = arquivos(j).name;
	posPonto = findstr(tituloArq, '.');
	posPonto = posPonto(end) - 1;
	tituloArq = tituloArq(1:posPonto);
	imwrite(I, ['document3x3/', tituloArq, '.pbm'], 'Encoding', 'rawbits');
end
fclose('all');
