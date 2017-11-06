void
cyclemon(Monitor *mon)
{
    Monitor *m;

    if (mon == mons)
        mons = mons->next;
    else {
        for (m = mons; m && m->next != mon; m = m->next);
        m->next = mon->next;
    }
}


void
reapplyrules(const Arg *arg) {
    Monitor *m;

    for (m = mons; m; m = m->next)
        while (mons)
            cyclemon(mons);

    setup();
    scan();
}
