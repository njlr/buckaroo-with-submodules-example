# buckaroo-with-submodules-example

This repo shows how you can mix-and-match [Buckaroo](https://buckaroo.pm) packages with Git Submodules.


## The Setup

We are importing two libraries, `test-lib-a` and `test-lib-b`. `test-lib-a` is imported as a Git Submodule, whereas `test-lib-b` is imported using Buckaroo's GitHub integration.

Using these libraries, we build `app`, a C++ binary that prints `"A B"` using functions from `test-lib-a` and `test-lib-b`.


### Extra Configuration

Since `test-lib-a` does not use Buckaroo, we need to tell Buck where to find it manually. This is done using an entry in `.buckconfig`:

```
[repositories]
  test-lib-a = external/test-lib-a
```

Pretty simple actually!

Then, we need to add the library to the list of dependencies of `app`:

```
...
  deps = BUCKAROO_DEPS + [
    'test-lib-a//:a',
  ],
...
```

Note how we prefix the dependency with `test-lib-a//`.


## Fetching the Dependencies

Since we are using two methods for importing packages, this is a two-step process:

```
git submodule update --init
buckaroo install
```


## Building the Code

Once we have fetched the code, Buck makes this very simple:

```
buck build :app
```

Or to run it via Buck:

```
buck run :app
```
