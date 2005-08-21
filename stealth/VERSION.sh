. VERSION

echo "SUBST(_CurVers_)($VERSION)
SUBST(_CurYrs_)($YEARS)" > release.yo

echo "#define _CurVers_ \"$VERSION\"
#define _CurYrs_ \"$YEARS\"" > release.h
