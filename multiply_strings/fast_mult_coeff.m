function fast_mult_coeff
candidate = [-1 0 1];
basen = length(candidate);

sol = zeros(24, 1);
min_P_len = 7;
finished = false;
min_sol = sol;

while  (~finished)
	if check
		P = convert_sol
		if (length(unique(P)) < min_P_len)
			min_sol = sol;
			min_P_len = length(unique(P));
		end
	end

	finished = next_sol;
end

min_sol

	function y = convert(row, base)
		y = 0;

		for r = row,
			y = y * base + r;
		end
	end

	function y = convert_sol
		s = reshape(sol, 6, 4);
		y = zeros(1, 6);
		for ii=1:6,
			y(ii) = convert(s(ii, :), basen);
		end
	end

	function y = next_sol
		carry = 1;

		for ii=1:length(sol)
			sol(ii) = mod(sol(ii)+carry, basen);

			if sol(ii) == 0
				carry = 1;
			else
				carry = 0;
				break;
			end
		end

		if carry == 1,
			y = true;
		else
			y = false;
		end
	end

	function y = check
		alph = candidate(sol+1);
		alph = reshape(alph, 6, 4);

		B = zeros(4, 4);
		target = [0 0 1 1; 0 0 1 1; 1 1 0 0; 1 1 0 0];

		for ii=1:3,
			A = alph(2*ii-1, :)'*alph(2*ii, :);
			A = A + A';
			B = B + A;
		end

		if (isequal(B, target))
			y = true;
		else
			y = false;
		end
	end
end
