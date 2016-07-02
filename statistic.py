#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on 15:46:05 2016-07-02

@author: heshenghuan (heshenghuan@sina.com)
http://github.com/heshenghuan
"""

import sys
import commands

if __name__ == '__main__':
    date = commands.getoutput('date')
    easy = int(commands.getoutput('cat README.md | grep Easy | wc -l'))
    medium = int(commands.getoutput('cat README.md | grep Medium | wc -l'))
    hard = int(commands.getoutput('cat README.md | grep Hard | wc -l'))
    cpp = int(commands.getoutput('cat README.md | grep C++ | wc -l'))
    sh = int(commands.getoutput('cat README.md | grep Shell | wc -l'))
    py = int(commands.getoutput('cat README.md | grep Python | wc -l'))
    js = int(commands.getoutput('cat README.md | grep JavaScript | wc -l'))
    java = int(commands.getoutput('cat README.md | grep Java | wc -l'))
    sol = easy + medium + hard
    print date
    print "========================================"
    print "Statistics of Solutions:"
    print "Total                 %3d" % (sol)
    print "Easy solutions:       %3d  %2.2f%%" % (easy, (easy * 100.0 / sol))
    print "Medium solutions:     %3d  %2.2f%%" % (medium, (medium * 100.0 / sol))
    print "Hard solutions:       %3d  %2.2f%%" % (hard, (hard * 100.0 / sol))
    print "========================================"
    print "C++ solutions:        %3d  %2.2f%%" % (cpp, (cpp * 100.0 / sol))
    print "Java solutions:       %3d  %2.2f%%" % (java, (java * 100.0 / sol))
    print "Shell solutions:      %3d  %2.2f%%" % (sh, (sh * 100.0 / sol))
    print "Python solutions:     %3d  %2.2f%%" % (py, (py * 100.0 / sol))
    print "JavaScript solutions: %3d  %2.2f%%" % (js, (js * 100.0 / sol))
    print "========================================"

    f = open('./statis.log', 'a')
    f.write("\n\n" + date + '\n')
    f.write("========================================\n")
    f.write("Statistics of Solutions:\n")
    f.write("Total                 %3d\n" % (sol))
    f.write("Easy solutions:       %3d  %2.2f%%\n" %
            (easy, (easy * 100.0 / sol)))
    f.write("Medium solutions:     %3d  %2.2f%%\n" %
            (medium, (medium * 100.0 / sol)))
    f.write("Hard solutions:       %3d  %2.2f%%\n" %
            (hard, (hard * 100.0 / sol)))
    f.write("========================================\n")
    f.write("C++ solutions:        %3d  %2.2f%%\n" %
            (cpp, (cpp * 100.0 / sol)))
    f.write("Java solutions:       %3d  %2.2f%%\n" %
            (java, (java * 100.0 / sol)))
    f.write("Shell solutions:      %3d  %2.2f%%\n" % (sh, (sh * 100.0 / sol)))
    f.write("Python solutions:     %3d  %2.2f%%\n" % (py, (py * 100.0 / sol)))
    f.write("JavaScript solutions: %3d  %2.2f%%\n" % (js, (js * 100.0 / sol)))
    f.write("========================================\n")
    f.close()
