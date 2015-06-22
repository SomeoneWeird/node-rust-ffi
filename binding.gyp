{
  "targets": [
    {
      "target_name": "nativeaddon",
      "sources": [ "nativeaddon.cc" ],
      "include_dirs": [ 
        "<!(node -e \"require('nan')\")",
        "rust",
        "../rust",
        ".",
        "./build/Release"
      ],
      "libraries": [
        "../rust/library.dylib",
        "-L../build/Release"
      ],
      "copies": [
        {
          "files": [ "rust/library.dylib" ],
          "destination": "."
        }
      ]
    }
  ]
}
