close all;
clear all;

v = '9.1.3';
url = strcat('https://github.com/jmejia8/bilevel-benchmark/archive/v', v ,'.zip');
libpath = strcat('bilevel-benchmark-', v ,'/*');

disp('Downloading library...');
websave('lib.zip', url);

disp('Uzipping library...');
unzip('lib.zip','./');
mkdir 'bilevel-benchmark';
movefile(libpath, 'bilevel-benchmark');
rmdir(strcat('bilevel-benchmark-', v), 's');

display('Compiling PMM_leader...');
mex('CFLAGS="\$CFLAGS -std=c99 -lm"', 'PMM_leader.c');

display('Compiling PMM_follower...');
mex('CFLAGS="\$CFLAGS -std=c99 -lm"', 'PMM_follower.c');

display('Compiling PMM_Psi...');
mex('CFLAGS="\$CFLAGS -std=c99 -lm"', 'PMM_Psi.c');

disp('Done!');
