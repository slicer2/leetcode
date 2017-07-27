num_test_cases = 100;
test_len = 1000;

fid = fopen('infile', 'w');

for ii_tc = 1:num_test_cases
	a = round(rand(test_len, 1) * 10*test_len);
	a = sort(a);
	a_min = a(1);
	b = floor(rand * (test_len-1)) + 2;
	a = [a(b:end); a(1:b-1)];

	fprintf(fid, '%d\n', test_len);
	fprintf(fid, '%d\n', a_min);
	fprintf(fid, '%d\n', a);
end

a = round(rand(test_len, 1) * 10*test_len);
a = sort(a);

fprintf(fid, '%d\n', test_len);
fprintf(fid, '%d\n', a(1));
fprintf(fid, '%d\n', a);


fclose(fid);
