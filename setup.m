close all;
clear all;

url = 'https://github.com/jmejia8/bilevel-benchmark/archive/v9.1.1.zip';

disp('Downloading library...');
websave('lib.zip', url);

disp('Uzipping library...');
unzip('lib.zip','./');
mkdir 'bilevel-benchmark';
movefile 'bilevel-benchmark-9.1.1/*' 'bilevel-benchmark';
rmdir('bilevel-benchmark-9.1.1', 's');

display('Compiling PMM_leader...');
mex('CFLAGS="\$CFLAGS -std=c99 -lm"', 'PMM_leader.c');

display('Compiling PMM_follower...');
mex('CFLAGS="\$CFLAGS -std=c99 -lm"', 'PMM_follower.c');

disp('Done!');