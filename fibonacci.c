void
fibonacci(Monitor *mon, int s) {
	unsigned int i, n, nx, ny, nw, nh;
	unsigned int gap = gappx;
	Client *c;

	for(n = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next), n++);
	if(n == 0)
		return;

	nx = mon->wx;
	ny = mon->wy;
	nw = mon->ww;
	nh = mon->wh;

	for(i = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next)) {
		if((i % 2 && nh / 2 > 2 * c->bw + gap)
		   || (!(i % 2) && nw / 2 > 2 * c->bw + gap)) {
			if(i < n - 1) {
				if(i % 2)
					nh = (nh - gap) / 2;
				else
					nw = (nw - gap) / 2;

				if((i % 4) == 2 && !s)
					nx += nw + gap;
				else if((i % 4) == 3 && !s)
					ny += nh + gap;
			}

			if((i % 4) == 0) {
				if(s)
					ny += nh + gap;
				else
					ny -= nh + gap;
			}
			else if((i % 4) == 1)
				nx += nw + gap;
			else if((i % 4) == 2)
				ny += nh + gap;
			else if((i % 4) == 3) {
				if(s)
					nx += nw + gap;
				else
					nx -= nw + gap;
			}

			if(i == 0) {
				if(n != 1)
					nw = (mon->ww - gap) * mon->mfact;
				ny = mon->wy;
			}
			else if(i == 1)
				nw = mon->ww - nw - gap;

			i++;
		}

		resize(c, nx, ny,
			nw - 2 * c->bw,
			nh - 2 * c->bw,
			False);
	}
}

void
dwindle(Monitor *mon) {
	fibonacci(mon, 1);
}

void
spiral(Monitor *mon) {
	fibonacci(mon, 0);
}
