#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char randc(void){
    return rand()%94+32;
}

char* randstr(int a){
    char *t = (char *) malloc(a+1);
    for(int i = 0; i < a; ++i)
        t[i] = randc();
    t[a] = '\0';
    return t;
}

int main() {
    srand(time(NULL));

    int i = 1;
    for(;i <= 100; ++i){
        printf("%s\n", randstr(i));
    }

    printf("P__________________________________________________________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x008233520650577263596894436299899046732339864265947874234693012072988V6?;FOH3xmM5p4^/8~UAYld/|N.2<F~}vt5|[I#J0`P6YO1Ef8T366a'|PzZCgBN:8--`Lo<Z+jvh`NKPPPZEBYBKIXIPZDCKVWTQDKZRYVKVAWMJKBYXVXPTRCWWGLRHXCFGRWHVKPPBYHCBYKAQVXBYXFCGXHSYKKNGABBZOZABXCFRf3)S0_YGqi*Vp;4^#3V:{nmmeseb\n");
    printf("P___________________________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x33793449607524911669123905028038714501675004506910218720568085434367738183454419098V6pX&C*Fjgc73r'I3S|]](#\"T\"p6ukj7D!39,*|/`G'*H#~&''<d3V<6ERf6SE-[Ltco7c!G~S+*q]$1CwZxV:&ATbT@}`JJ9BIXCSNWMCPAOGLFOVXWXZZONCJVDPXPXTEYKMVEQZVMQNELQQGVJIWMHIWNH5zTaf0=JWRV 4ZN3=cz|YS,n[R1mmeseb\n");
    printf("G_____________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x009360856433387030094532573115295014122450191695168043873981823783427042463387927V6>k/>O2E*H=,9/+i#`*`tksrz4)yP_'|,XZYLMWTZQpnX`Igj``MW1|xgyp@k?(GN@gUGvwSE0sKti5)z_]=C,uIo(7mmeseb\n");
    printf("/_______________________________________________________________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x04169867994767152106075522942862323847V6R:Fvd bV1,IY_s_+6GMUzyO9-Z*m|I51FE:c8g~yyZti`/4dD/GZr,Z'# gWv9HL>15$$>o\\rSH\\|IAfNG8lcso?n[RFHfHJMSJMJTSBPANRRLCWTNBLKZJUBJPPXFEB79IKEa_K+UwoNq{@g1y>E&>|LT6S\"*]b\\M!jP4!JoLTE!}-]NhGgVa]&if)mmeseb\n");
    printf(":__________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x02549119312767V6>v49y&C8+_=Jwof]8t :sKN&T2EeJgsENMJBKGERNBBJMPPJKSZMDOGDXYDVPSJJLZGSZRZZCBOCUWZRHBOYZEPVOGWHOPLQZNQOOFJFUZMAVGFEFYLVLABPXWRHL)4>Z#BnNltn#?E_s|.U!-_GHN73,tOa['e9YqA6LJrKp>\\|TH.AW$a(d3x@C]^cIY\\YzjT];#FZc{\\'mmeseA\n");
    printf("_0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x58437138315759985421480811183240426690982377V6F^{d&^d,D[>G_rAhdL9;RuU'`mU7m<j&N6g:mRC8.yKT/i3lQ]Y[U]{8lL4GmPLCTNSEZEOODLGOPQPBGOSUlJps@|F!6V=Y4x:c_pouR:}EW#PY_\"69r9$+~/BVW|8T)/h!>[mw^Wcmmeseb\n");
    printf("l_________________________________________________________________________________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x082152930162034092938903409508228203158950733444294894272919784376918230748501241734593943486262587V6noa1q3xgLXV-Y,eaQj6fCNUCABVXIVUSEAHOWSLVYCEFCJRVZUYQOHOCPEWEUMMXAMVIJQUYCXRBHHGUBYS6Afz|q 6gTfwvO9:+^BGo-AK?U-.au?/oL1J_-UVs1xmmeseb\n");
    printf("o___________________________________________________________________________________0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x0x290922899151068519456191857303986761026234511627707396970665265684721488V6=,;8FMOMJQIKCBOSJHWTMQYICAr\\*5.ivn3iXQy0n1>xWz$rmmeseA\n");

    for(;i <= 205; ++i){
        printf("%s\n", randstr(i));
    }

    return 0;
}