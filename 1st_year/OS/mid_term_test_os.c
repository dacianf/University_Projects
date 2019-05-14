
#!/bin/bash
rm *info
for fl in $(find);do
        if [[ -f $fl && -r $fl ]]; then
                #touch $fl\.info
                echo $(du -b $fl | awk '{printf("size: %s\n",$1);}') > $fl\.info
                echo $(ls -l $fl | awk '{printf("date: %s %s %s\n",$6,$7,$8);}') >> $fl\.info
                echo $(file $fl | cut -d':' -f2) >> $fl\.info
        fi
done
