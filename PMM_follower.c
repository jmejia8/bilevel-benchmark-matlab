#include "mex.h"
#include "bilevel-benchmark/pmm.c"

/* The gateway function */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[])
{

    /* check for proper number of arguments */
    if(nrhs!=3) {
        mexErrMsgIdAndTxt("MyToolbox:pmm:nrhs","Three inputs required (x, y, fnum).");
    }

    /* make sure the first input argument is scalar */
    // if( !mxIsDouble(prhs[3])) {
    //     mexErrMsgIdAndTxt("MyToolbox:pmm:notScalar","Input multiplier must be a scalar.");
    // }
    

    int i;
    for (i = 0; i < 2; ++i) {
        /* make sure the second input argument is type double */
        if( !mxIsDouble(prhs[i]) || 
             mxIsComplex(prhs[i])) {
            mexErrMsgIdAndTxt("MyToolbox:pmm:notDouble","Input vectors must be type double.");
        }
        
        /* check that number of rows in second input argument is 1 */
        // if(mxGetM(prhs[i])!=1) {
        //     mexErrMsgIdAndTxt("MyToolbox:pmm:notRowVector","Input must be a row vector.");
        // }
    }
    
    int D_ul = mxGetN(prhs[0]);
    // int D_ll = mxGetN(prhs[1]);
    int m = D_ul/2, n = D_ul;

    double *x = (double *) mxGetPr(prhs[0]);
    double *y = (double *) mxGetPr(prhs[1]);


    size_t fnum = mxGetScalar(prhs[2]);

    /* get a pointer to the real data in the output matrix */
    plhs[0] = mxCreateDoubleMatrix(1,(mwSize) 1,mxREAL);
    plhs[1] = mxCreateDoubleMatrix(1,(mwSize) 2,mxREAL);

    double *F = mxGetPr(plhs[0]);
    double *G = mxGetPr(plhs[1]);

    /* call the computational routine */
    PMM_follower(m, n, x, y, F, G, (int) fnum);
}
