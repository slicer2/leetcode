N = 2000;
L = 100;
A = 500;

alph = 'abcdefghijklmnopqrstuvwxyz';

r = randi(26, N, L);

strs = repmat(repmat('a', 1, L), N+A, 1);

for i=1:N
	strs(i, :) = alph(r(i, :));
end

strs(N+1:end, :) = strs(randi(N, A, 1), :);

for i=1:A,
	rnd = rand(1, L);
	[~, ix] = sort(rnd);

	strs(N+i, :) = strs(N+i, ix);
end

fid = fopen('infile1', 'w');

for i=1:(N+A),
	fprintf(fid, '%s\n', strs(i, :));
end

fclose(fid);
