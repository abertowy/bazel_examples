#!/usr/bin/env python3

import os
import sys
import unittest


class IntegrationTest01(unittest.TestCase):
    testfile = None

    def setUp(self):
        self._filepath = os.path.abspath(self.testfile)
        dummyfile = self._filepath + "/.dummy"
        if os.path.exists(dummyfile):
            os.remove(dummyfile)


    def test_path_created(self) -> None:
        print(self._filepath)
        self.assertTrue(os.path.exists(self._filepath))

    def test_path_empty(self) -> None:
        self.assertEqual(len(os.listdir(self._filepath)), 0)


if __name__ == "__main__":
    print(sys.argv)
    if len(sys.argv) > 1:
        IntegrationTest01.testfile = sys.argv.pop()
    unittest.main()

